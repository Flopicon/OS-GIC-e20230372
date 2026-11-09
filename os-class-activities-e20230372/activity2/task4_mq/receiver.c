
/* receiver.c — Receives a message through a POSIX message queue */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "common.h"

int main() {
    mqd_t mq;
    char buffer[MAX_SIZE + 1];

    /* Open the existing message queue */
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        fprintf(stderr, "Hint: Did you run sender first?\n");
        exit(EXIT_FAILURE);
    }

    /* Receive the message */
    ssize_t bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");
        mq_close(mq);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';

    printf("Receiver: message received from queue '%s'\n", QUEUE_NAME);
    printf("Receiver: message = \"%s\"\n", buffer);

    /* Close and remove the message queue */
    mq_close(mq);

    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: message queue unlinked.\n");

    return 0;
}
