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

#endif
