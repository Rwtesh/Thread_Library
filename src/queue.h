#ifndef QUEUE_H
#define QUEUE_H
#include<stddef.h>
#include "thread.h"
typedef struct queue
{
  thread* front;
  thread* rear;
  size_t size;
}queue;

void queue_initialize(queue* q);
void enqueue(queue* q, thread* t);
thread* dequeue(queue* q);
bool isEmpty(queue* q);

#endif
