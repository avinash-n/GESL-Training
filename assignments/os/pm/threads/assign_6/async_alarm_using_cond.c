/*
 * Avinash N
 * 02/02/2017
*/

/*
 * Asynchronous alarm using mutex and condition
*/

#include "errors.h"

unsigned long int time_1;
unsigned long int time_2;
char msg_temp[MSG_LEN];

// Alarm structure
typedef struct st_alarm {
	int sec;					// Member to hold time in seconds
	char msg[MSG_LEN];			// Member to hold the message
	struct st_alarm *next;		// Pointer to next node of alarm
} set_alarm;

// Mutex structure
struct mut {
	pthread_mutex_t th_mutex;	// Member for locking shared resource
	pthread_cond_t cond_1;
	pthread_cond_t cond_2;	
	set_alarm *head;
} th_mut = {.th_mutex = PTHREAD_MUTEX_INITIALIZER,
			.cond_1 = PTHREAD_COND_INITIALIZER,
			.cond_2 = PTHREAD_COND_INITIALIZER};

// Function to insert node of new alarm
void insert_node (set_alarm *node) {
	set_alarm *temp_curr = NULL;	// Temporary pointer to current node
	set_alarm *temp_prev = NULL;	// Temporary pointer to previous node
	int count = 0;
	static int flag = 0;

	if ((temp_curr = (set_alarm *) malloc (sizeof (set_alarm))) == NULL)
		errno_abort ("malloc() failed\n");
 
	temp_curr = th_mut.head;

	if ((temp_prev = (set_alarm *) malloc (sizeof (set_alarm))) == NULL)
		errno_abort ("malloc() failed\n");

	if (th_mut.head == NULL) {					// Check for head node
		if ((flag == 1) && ((node -> sec) < (time_1))) {
			th_mut.head = /*(set_alarm *)*/ node;
			node -> next = NULL;
			pthread_cond_signal (&th_mut.cond_2);
		} else {
			th_mut.head = /*(set_alarm *)*/ node;
			node -> next = NULL;
			pthread_cond_signal (&th_mut.cond_1);
			flag = 1;
  	}
	} else {
		while ((temp_curr -> next != NULL) && ((node -> sec) > (temp_curr -> sec))) {
			count++;
			temp_prev = temp_curr;
			temp_curr = temp_curr -> next;
		}

		if ((temp_curr -> next == NULL) && ((node -> sec) > (temp_curr -> sec))) {
			temp_curr -> next = node;
			node -> next = NULL;
		} else if (count == 0) {
			if ((temp_curr != NULL) && ((node -> sec) <= (temp_curr -> sec))) {
				node -> next = temp_curr;
				th_mut.head = node;
				pthread_cond_signal (&th_mut.cond_2);
			} else {
				th_mut.head= node;
				node -> next = NULL;
				pthread_cond_signal (&th_mut.cond_2);
			}
		} else {
			temp_curr = temp_prev;
			node -> next = temp_curr -> next;
			temp_curr -> next = node;
		}
	}
}

// Function to delete the node of alarm after servicing
void delete_node (void) {
	set_alarm *temp = NULL;		// To delete serviced node

	temp = (set_alarm *) th_mut.head;
	time_1 = temp -> sec;
	strcpy (msg_temp, temp -> msg);
	th_mut.head = (set_alarm *) temp -> next;

	free (temp);
	temp = NULL;
}

// Thread to service alarm
void *alarm_thread (void *arg) {
	int th_status;
	struct timespec th_time;

	while (1) {
		pthread_mutex_lock (&th_mut.th_mutex);
		if (th_status != 0)
			err_abort (th_status, "pthread_thread_lock() failed\n");

		if (th_mut.head == NULL) {
			th_status = pthread_cond_wait (&th_mut.cond_1, &th_mut.th_mutex);
			if (th_status != 0)
				err_abort (th_status, "pthread_cond_wait() failed\n");
		}

		delete_node ();	// Delete the serviced node

		time_2 = time_1 - time (NULL);
		th_time.tv_sec = time_1;

		if ((pthread_cond_timedwait (&th_mut.cond_2, &th_mut.th_mutex, &th_time)) == 110) {
			printf ("(%lu) %s\n", time_2, msg_temp);
			pthread_mutex_unlock(&th_mut.th_mutex);
		} else {
			set_alarm *back = (set_alarm *) malloc (sizeof (set_alarm));
			back -> sec = time_1;
			strcpy (back -> msg, msg_temp);
			insert_node (back);
			pthread_mutex_unlock (&th_mut.th_mutex);
		}
	}
	return NULL;
}

// Main thread to get user input and handle it through the thread function
int main (void) {
	set_alarm *th_alarm = NULL;		// Temporary node in main()
	char line[2 * MSG_LEN];			// Stream to take input from the user
	int status;						// To monitor return value of function calls
	pthread_t th_id;				// Instance of thread
	unsigned int seconds;			// User input time in seconds

	status = pthread_create (&th_id, NULL, alarm_thread, NULL);
	if (status != 0)
		err_abort (status, "pthread_create() failed\n");

	while (1) {
		printf ("Alarm : ");

		if (fgets (line, sizeof (line), stdin) == NULL) exit (1);
		if (strlen (line) <= 1) {
			//free (th_alarm);
			//th_alarm = NULL;
			continue;
		}

		if ((th_alarm = (set_alarm *) malloc (sizeof (set_alarm))) == NULL)
			errno_abort ("malloc() failed\n");

		if ((sscanf (line, "%d %64[^\n]", &seconds, th_alarm->msg)) < 2) {
			fprintf (stderr, "%s", "Bad command\n");
			free (th_alarm);
			th_alarm = NULL;
			continue;
		}

		th_alarm -> sec = seconds + time (NULL);
//		printf("%d %s\n", th_alarm->sec, th_alarm->msg);

		status = pthread_mutex_lock (&th_mut.th_mutex);
		if (status != 0)
			err_abort (status, "pthread_thread_lock() failed\n");

		insert_node (th_alarm);

		status = pthread_mutex_unlock (&th_mut.th_mutex);
		if (status != 0)
			err_abort (status, "pthread_thread_unlock() failed\n");
	}

//	printf("%d %s\n", th_alarm -> sec, th_alarm -> msg);
	pthread_exit (NULL);
	return 0;
}
