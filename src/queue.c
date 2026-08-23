#include "queue.h"

void queue_initialize(queue* q)
{
  q->front=NULL;
  q->rear=NULL;
  q->size=0;
}

bool is_empty(queue* q)
{
  return (q->size==0);
}

void enqueue(queue* q, thread* t)
{
  t->next=NULL;
  if(q->size==0)
  {
    q->front=q->rear=t;
  }
  else
  {
    q->rear->next = t;
    q->rear=q->rear->next;
  }
  q->size++;
}

thread* dequeue(queue* q)
{
  if(q->size==0)return NULL;
  thread* temp;
  if(q->size==1)
  {
    temp = q->front;
    q->rear=q->front=NULL;
    q->size--;
  }
  else
  {
    temp=q->front;
    q->front=q->front->next;
    q->size--;
  }
  temp->next=NULL;
  return temp;
}
