#include "../include/uthreads.h"

struct scheduler
{
    ucontext_t schedCtx;
    thread* current;
    thread* head,*tail;
};

void entryPoint(thread* tf,scheduler* s)
{
    tf->fn(tf->arg);
    tf->state=T_FINISHED;
    return;
}

thread* threadInit(scheduler* s,threadFunc tf,void* arg,int stsz)
{
    thread* temp=(thread*)malloc(sizeof(thread));
    getcontext(&temp->ctx);
    temp->stack_size=stsz;
    temp->stack=calloc(1,stsz);
    temp->ctx.uc_stack.ss_sp=temp->stack;
    temp->ctx.uc_stack.ss_size=temp->stack_size;
    temp->ctx.uc_link=&s->schedCtx;
    temp->arg=arg;
    temp->state=T_READY;
    temp->next=NULL;
    temp->fn=tf;
    if(!s->tail)s->head=s->tail=temp;
    else 
    {
        s->tail->next=temp;
        s->tail=temp;
    }
    makecontext(&temp->ctx,(void(*)())entryPoint,2,temp,s);

    return temp;
}

scheduler* schedulerInit()
{
    scheduler* s=(scheduler*)malloc(sizeof(scheduler));
    s->head=s->tail=s->current=NULL;
}

void schedulerRun(scheduler* s)
{
    if(!s->head)return;

}

void threadYield(scheduler* s)
{

}

void threadExit(scheduler* s)
{

}

void schedulerDest(scheduler* s)
{

}