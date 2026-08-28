#include "scheduler.h"
#include "queue.h"

void scheduler_init(scheduler* s)
{
  s->stack = malloc(4*1024);
  s->curr = NULL;
  s->main = NULL;
  queue_initialize(&s->readyQueue);
  s->totalThreads=0;

  getcontext(&s->ctx);
  s->ctx.uc_link=NULL;
  s->ctx.uc_stack.ss_sp=s->stack;
  s->ctx.uc_stack.ss_size=4*1024;
  s->ctx.uc_stack.ss_flags=0;
  makecontext(&s->ctx,(void (*)(void))scheduler_enter,1,s);
}

void scheduler_addThread(scheduler* s,thread* t)
{
  t->state=READY;
  enqueue(&s->readyQueue,t);
}

void scheduler_run(scheduler* s)
{
  if(is_empty(&s->readyQueue))
    return;
  swapcontext(&s->main->ctx,&s->ctx);
}

static void scheduler_enter(scheduler* s)
{
  while(s->totalThreads>0)
  {
    if(is_empty(&s->readyQueue))break;
    
    thread* temp=dequeue(&s->readyQueue);
    s->curr=temp;
    temp->state=RUNNING;

    swapcontext(&s->ctx,&temp->ctx);

    if(temp->state=READY)
      enqueue(&s->readyQueue,temp);
    else if(temp->state=TERMINATED)
    {
      s->totalThreads--;
      free(temp->stack);   
    }
  }
  setcontext(&s->main);
}


