#include <stdio.h>
#include "threads.h"

typedef struct {
    const char *name;
    int limit;
} Task;

void worker(void *arg)
{
    Task *t = (Task *)arg;

    for (int i = 1; i <= t->limit; i++) {
        printf("[%s] step %d/%d\n", t->name, i, t->limit);
        if (i % 2 == 1) {
            thread_yield();
        }
    }
}

void chatter(void *arg)
{
    (void)arg;
    for (int i = 0; i < 4; i++) {
        printf("[chatter] ping %d\n", i);
        thread_yield();
    }
}

int main(void)
{
    threads_init();

    Task a = { "alpha", 6 };
    Task b = { "beta", 5 };

    int id1 = thread_create(worker, &a);
    int id2 = thread_create(worker, &b);
    int id3 = thread_create(chatter, NULL);

    printf("created threads: %d %d %d\n", id1, id2, id3);

    threads_run();

    printf("all threads finished\n");
    return 0;
}
