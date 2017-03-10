/*
 * Avinash N
 * 06/02/2017
 */

/*
 * List all the configuration options available to configure the message queues.
 * Classify them based on the parameters used to configure the message queue
 * and messages.
 * Test for all extreme configurable values of message queues in assignment 4.
*/

#include "errors.h"

int main (void) {
	mqd_t tom;
	struct mq_attr *attr;
	char *buf = NULL; 
	int status;
	char buff[5] = "bye";

	buf = (char *) malloc (sizeof (char) *STR_LEN);

	tom = mq_open ("/tom", O_CREAT | O_RDWR, 0666, NULL);
	printf ("tomm\n");

	while(1) {
		fgets (buf, STR_LEN, stdin);

		status = mq_send (tom, buf, strlen(buf), 6);
		if (status < 0) err_abort ("mq_send() in tom failed\n");

		memset (buf, '\0', strlen (buf));

		status = mq_receive (tom, buf, attr->mq_msgsize, NULL);
		if (status < 0) err_abort ("mq_recevie() in tom failed\n");

		printf ("%s\n", buf);

		if ((strcasecmp (buf, buff) == 10) ||
			(strcasecmp (buf, buff) == 0)) {
			memset (buf, '\0', strlen (buf));
			status = mq_send (tom, buff, strlen (buff), 6);
			if (status < 0) err_abort ("mq_send() in tom failed\n");
				mq_close (tom);
				mq_unlink ("/tom");
				exit(0);
		}
	}
	return 0;
}
