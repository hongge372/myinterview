#include<iostream>

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<errno.h>

using namespace std;

#define return_if_fail(p) if((p)==0){printf("[%s]:func eror!\n", __FUNCTION__);return -1;}

typedef struct PrivInfo
{
  sem_t s1;
  sem_t s2;
  time_t end_time;
}PrivInfo;

static int info_init(PrivInfo *thiz);
static int info_destroy(PrivInfo *thiz);
static void *pthread_func_1(void *args);
static void *pthread_func_2(void *args);

int main(int argc, char* argv[])
{
  pthread_t pt_1;
  pthread_t pt_2 = 0;

  int ret = 0;

  PrivInfo *thiz = NULL;
  thiz = (PrivInfo *)malloc(sizeof(PrivInfo));
  if(thiz == NULL){
    printf("%s : failed to malloc. \n", __FUNCTION__);
    return -1;
  }
    info_init(thiz);
    //    ret = pthread_create(&pt_1, NULL, pthread_func_1, thiz);
    //pthread_create(&pt_1, NULL, pthread_func_1, NULL);
    ret = pthread_create(&pt_1, NULL, pthread_func_1, thiz);
    if(ret != 0){
      perror("pthread 1 chreate ");
    }

    ret = pthread_create(&pt_2, NULL, pthread_func_2, thiz);
    if(ret != 0){
      perror("Pthread 2 create ");
    }
    pthread_join(pt_1, NULL);
    pthread_join(pt_2, NULL);
    info_destroy(thiz);
    return 0;
  }

static int info_init(PrivInfo *thiz)
{
  return_if_fail(thiz==NULL);
  thiz->end_time = time(NULL) + 10;
  sem_init(&thiz->s1, 0, 1);
  sem_init(&thiz->s2, 0, 0);
  return 0;
}

static int info_destroy(PrivInfo *thiz)
{
  return_if_fail(thiz != NULL);
  sem_destroy(&thiz->s1);
  sem_destroy(&thiz->s2);
  free(thiz);
  thiz = NULL;
  return 0;
}

static void *pthread_func_1(void *args)
{
  PrivInfo *thiz =(PrivInfo *) args;
  //return_if_fail(thiz != NNULL);
  while(time(NULL) < thiz->end_time)
    {
      sem_wait(&thiz->s2);
      printf("pthread : get the lock \n");
      sem_post(&thiz->s1);
      printf("pthred1 pthread unlock n");
      sleep(1);
    }
}

static void *pthread_func_2(void *args)
{
  PrivInfo *thiz =(PrivInfo *) args;
  //return_if_fail(thiz != NULL);
  while(time(NULL) < thiz->end_time)
    {
      sem_wait(&thiz->s1);
      printf("pthread2 get the lock \n");
      sem_post(&thiz->s2);
      printf("pthread2  pthread unlock \n");
      sleep(1);
    }
}

