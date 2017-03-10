/*
 * Avinash N
 * 06/02/2017
 */

/*
 * Write two independent applications tom and jerry which will communicate
 * using message queues. tom writes a message to jerry to accomplish some job
 * and once the job is completed jerry replies back the status of the job
 * to tom through the same message queue.
 * Mount the message queue file system onto /dev/mqueue and diagnose the message * queues.
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
