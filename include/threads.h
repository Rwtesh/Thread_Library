#ifndef THREADS_H
#define THREADS_H

typedef void(*threadFn)(void* arg);
typedef struct thread thread;

void threads_init(void);
int thread_create(threadFn fn,void* arg);
void threads_run(void);
void thread_yield(void);
void thread_exit(void);

#endif
