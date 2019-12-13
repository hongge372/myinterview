#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

using namespace std;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int shared = 0;

static void cleanup_handler(void *arg)
{
  printf("Cleanup handler of second thread. \n");
  free(arg);
  pthread_mutex_unlock(&mtx);
}

static void *thread_func(void *arg)
{
  pthread_cleanup_push(cleanup_handler, arg);
  while(1)
    {
      pthread_mutex_lock(&mtx);
      pthread_cond_wait(&cond, &mtx);
      printf("child thread, shared:= %d \n", shared);
      shared++;
      pthread_mutex_unlock(&mtx);
    }
  pthread_mutex_unlock(&mtx);
  pthread_cleanup_pop(0);
}

int main(int argc, char *argv[])
{
  pthread_t tid;
  int i;
  pthread_create(&tid, NULL, thread_func, NULL);
  sleep(1);

  for(i=0; i<10; i++){
    pthread_mutex_lock(&mtx);
    shared*=2;
    printf("main thread, shared:= %d \n", shared);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
    sleep(1);
  }

  printf("thread 1 wanna end the line. cancel thread 2 \n");

  pthread_cancel(tid);
  pthread_join(tid, NULL);

  return 0;
}
