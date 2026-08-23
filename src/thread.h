#ifndef THREAD_H
#define THREAD_H
#include <ucontext.h>
#include <stdlib.h>
#include "threads.h"
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
  ucontext_t ctx;
  threadFn fn;
  void* arg;
  void* stack;
  int stackSize;
  thread_state state;
  struct thread* next;
}thread;

#endif
