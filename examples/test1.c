#include <stdio.h>
#include "threads.h"

void A(void* arg)
{
  int i=5;
  while(i)
  {
    printf("A\n");
    i--;
    thread_yield();
  }
}
void B(void* arg)
{
  int i=5;
  while(i)
  {
    printf("B\n");
    i--;
    thread_yield();
  }
}

int main()
{
  threads_init();
  thread_create(A,NULL);
  thread_create(B,NULL);
  threads_run();
  return 0;
}
