#include "scheduler.h"
#include "thread.h"

scheduler s;
static int next_id=0;

void threads_init(void)
{
  scheduler_init(&s);
  next_id=1;
}

static void trampoline(thread* t)
{
  t->fn(t->arg);
  thread_exit();
}
int thread_create(threadFn fn, void* arg)
{
  if(!next_id)return -1;
  thread* t=(thread*)malloc(sizeof(thread));
  if(!t)return -1;
  t->stackSize=64*1024;
  t->stack=malloc(t->stackSize);
  if(!t->stack)
  {
    free(t);
    return -1;
  }
  t->state=READY;
  t->fn=fn;
  t->arg=arg;
  t->id=next_id++;
  
  if(getcontext(&t->ctx)==-1)
  {
    free(t->stack);
    free(t);
    return -1;
  }
  t->ctx.uc_link=NULL;
  t->ctx.uc_stack.ss_sp=t->stack;
  t->ctx.uc_stack.ss_size=t->stackSize;
  t->ctx.uc_stack.ss_flags=0;
  makecontext(&t->ctx,(void (*)(void))trampoline,1,t);
 
  scheduler_addThread(&s,t);
  return t->id;
}

void threads_run(void)
{
  scheduler_run(&s);
}

void thread_yield(void)
{
  if(!next_id||!s.curr)return;
  thread* temp=s.curr;
  temp->state=READY;
  swapcontext(&temp->ctx,&s.ctx);
}

void thread_exit(void)
{
  if(!next_id||!s.curr)return;
  thread* temp=s.curr;
  temp->state=TERMINATED;
  setcontext(&s.ctx);
}
