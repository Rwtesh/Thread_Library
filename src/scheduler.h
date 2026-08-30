#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "thread.h"
#include "queue.h"
#include<stddef.h>
typedef struct scheduler
{
  ucontext_t ctx;
  void* stack;

  ucontext_t main_ctx;
  thread* curr;         //To return once all threads have terminated
  queue readyQueue;
  // queue finishedQueue;    //To free the stacks of finished threads
  size_t totalThreads;
}scheduler;

void scheduler_init(scheduler* s);
void scheduler_addThread(scheduler* s,thread* t);
void scheduler_run(scheduler* s);
// void scheduler_enter(scheduler* s);
#endif
