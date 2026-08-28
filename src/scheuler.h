#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "thread.h"
#include "queue.h"
#include<stddef.h>
typedef struct scheduler
{
  ucontext_t ctx;
  void* stack;

  thread* curr;
  thread* main;         //To return once all threads have terminated
  queue readyQueue;
  // queue finishedQueue;    //To free the stacks of finished threads
  size_t totalThreads;
}scheduler;

void scheduler_init(scheduler* s);
void scheduler_addThread(scheduler* s,thread* t);
void scheduler_run(scheduler* s);
void scheduler_exit(scheduler* s);
void scheduler_yield(scheduler* s);
void scheduler_enter(void);
#endif
