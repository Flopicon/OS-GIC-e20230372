#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

void *worker(void *arg) {
    int id = *(int *)arg;

    printf("Worker %d: started (TID: %lu)\n",
           id, (unsigned long)pthread_self());

    sleep(60);

    printf("Worker %d: finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    printf("Process PID: %d\n", getpid());
    printf("Creating %d worker threads...\n", NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    printf("Threads are running. Observe them now!\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");
    return 0;
}
