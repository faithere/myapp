#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/********************global variable********************/
char *message="hello thread";
int thread_finished=0;
/********************global variable********************/


void * thread_function(void * arg)
{
  printf("thread function is running.Argument is =%s\n",arg);
  sleep(10);
  printf("Second thread setting finished flag, and exiting now\n");
  thread_finished=1;
  pthread_exit(NULL);
}

int main(void)
{
  int res;
  pthread_t new_thread;
  void *thread_result;
  
  pthread_attr_t thread_attr;

  res=pthread_attr_init(&thread_attr);
  if (res!=0)
    {
      perror("Attribute creation failel");
      exit(EXIT_FAILURE);
    }
  res=pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
  if (res!=0)
    {
      perror("Setting detached attribute failed");
      exit(EXIT_FAILURE);
    }

  res=pthread_create(&new_thread,&thread_attr,thread_function,(void *)message);
  if (res)
    {
      perror("Thread create failed!\n");
      exit(EXIT_FAILURE);
    }
  (void)pthread_attr_destroy(&thread_attr);
  while(!thread_finished)
    {
      printf("Waiting for thread to say it's finished...\n");
      sleep(1);
    }
  printf("Other thread ended! I'm go! Bye\n");
  exit(EXIT_SUCCESS);
}
   
