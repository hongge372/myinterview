#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t stu_mutex;
pthread_cond_t cond;

void hander(void *arg)
{
  free(arg);
  //(void)pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&stu_mutex);
}

void *thread1(void *arg)
{
  pthread_cleanup_push(hander, &stu_mutex);
  while(1){
    //printf("thread 1 is running \n");
    pthread_mutex_lock(&stu_mutex);
    pthread_cond_wait(&cond, &stu_mutex);
    printf("thread 1 applied the condition \n");
    pthread_mutex_unlock(&stu_mutex);
    pthread_cond_signal(&cond);
    sleep(4);
  }
  pthread_cleanup_pop(0);
}

void *thread2(void *arg)
{
  while(1)
    {
      //printf("thead 2 is running \n");
      pthread_mutex_lock(&stu_mutex);
      pthread_cond_wait(&cond, &stu_mutex);
      printf("thread2 applied the condition \n");
      pthread_mutex_unlock(&stu_mutex);
      pthread_cond_signal(&cond);
      sleep(1);
    }
}

int main(int argc, char* argv[])
{
  pthread_t thid1, thid2;
  printf("condition variable study! \n");
  pthread_mutex_init(&stu_mutex, NULL);
  pthread_cond_init(&cond, NULL);
  pthread_create(&thid1, NULL, thread1, NULL);
  pthread_create(&thid2, NULL, thread2, NULL);
  sleep(1);
  do{
    pthread_cond_signal(&cond);
  }while(0);

  sleep(20);
  pthread_exit(0);
  return 0;
}
