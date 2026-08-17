#ifndef THREADS_H
#define THREADS_H
#include <ucontext.h>
#include <stdlib.h>

typedef enum thread_state
{
  READY,
  RUNNING,
  BLOCKED,
  TERMINATED
}thread_state;

typedef struct thread
{
  int id;
  ucontext* ctx;
  void* stack;
  int stackSize;
  thread_state state;
  struct thread* next;
}thread;

typedef struct queue
{
  thread* front;
  thread* rear;
  size_t size;
}queue;

typedef struct scheduler
{
  thread* curr;
  queue readyQueue;
  // queue finishedQueue;    //To free the stacks of finished threads
  size_t totalThreads;
}scheduler;

#endif
