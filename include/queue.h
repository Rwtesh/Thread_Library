#ifndef QUEUE_H
#define QUEUE_H

#include "threads.h"

void queue_initialize(queue* q);
void enqueue(queue* q, thread* t);
thread* dequeue(queue* q);
bool isEmpty(queue* q);

#endif
