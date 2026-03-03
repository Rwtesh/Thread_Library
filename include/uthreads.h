#ifndef UTHREADS_H
#define UTHREADS_H
#include <stdlib.h>
#include <ucontext.h>

typedef void(*threadFunc)(void* arg);
typedef enum
{
    T_READY,
    T_RUNNING,
    T_FINISHED
} T_STATE;

typedef struct thread
{
    ucontext_t ctx;
    void* stack;
    int stack_size;
    threadFunc fn;
    T_STATE state;
    struct thread* next;
}thread;

typedef struct scheduler scheduler;

scheduler* schedulerInit(void);
void schedulerDest(scheduler* s);

thread* threadInit(scheduler* s,threadFunc tf,void* arg,int stsz);

void threadYield(scheduler* s);
void threadExit(scheduler* s);

#endif 
