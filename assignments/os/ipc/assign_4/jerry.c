/*
 * Avinash N
 * 06/02/2017
 */

/*
 * Write two independent applications tom and jerry which will communicate
 * using message queues. tom writes a message to jerry to accomplish some job
 * and once the job is completed jerry replies back the statusatus of the job
 * to tom through the same message queue.
 * Mount the message queue file systatusem onto /dev/mqueue and diagnose the message * queues.
 */

#include "errors.h"

int main (void) {
	mqd_t jerry;
	char *buf;
	struct mq_attr *attr;
	int status;
	char buff[5] = "bye";

	buf = (char *) malloc (sizeof (char) *STR_LEN);
	jerry = mq_open ("/tom", O_RDWR);

	printf ("jerry\n");

	while (1) {
		status = mq_receive (jerry, buf, attr->mq_msgsize, NULL);
		if (status < 0) err_abort ("mq_recevie() in jerry failed\n");
		printf ("%s\n", buf);

		if ((strcasecmp (buf, buff) == 10) || strcasecmp (buf, buff) == 0) {
			memset (buf, '\0', strlen (buf));
			status = mq_send (jerry, buff, strlen (buff), 3);
			if (status < 0) err_abort ("mq_send() in jerry failed\n");
			mq_close (jerry);
			mq_unlink ("/tom");
			exit (0);
		}

		memset (buf, '\0', strlen (buf));
		fgets (buf, STR_LEN, stdin);

		status = mq_send (jerry, buf, strlen (buf), 3);
		if (status < 0) err_abort ("mq_send() in jerry failed\n");

		memset (buf, '\0', strlen (buf));
	}
	return 0;
}
