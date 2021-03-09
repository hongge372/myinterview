#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

static int inited = 0;
static int complete = 0;
static int loop = 10;
static int mydata = 0;
static int flg = -1; 

pthread_cond_t cond;
pthread_mutex_t mtx;

static void *be_call(void *args)
{

  sleep(3);
  mydata = 1;
  inited = 1;
  
  while(1){
    printf("be_call waitting mtx\n");
    if(flg>0){
    pthread_mutex_lock(&mtx);
    }else{
      sleep(1);
      continue;
    }
    printf("be_call waitting cond \n");
    pthread_cond_wait(&cond, &mtx);
    printf("BeCall thread, my data:= %d , and will be:= %d \n ", mydata, mydata+1);
    mydata+=1;
    sleep(1);
    flg = 0;
    pthread_mutex_unlock(&mtx);
  }

  return NULL;
}


static void *call(void *args)
{
  int i=0;

  while(!inited){
    printf("waitting for ininted ok \n");
    sleep(1);
  }

  while(i<loop){
    if(flg <=0){
      pthread_mutex_lock(&mtx);
    }else{
      printf("Call flg is :=%d \n", flg);
      sleep(1);
      continue;
    }
    printf("Call thread mydata:= %d, and will be:= %d \n", mydata, mydata*2);
    mydata*=2;
    flg =1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
    printf("one loop end call \n");
  }
  complete = 1;

  return NULL;
}


int main(int argc, char* argv[])
{
  pthread_t pid[2];

  cond = PTHREAD_COND_INITIALIZER;
  mtx = PTHREAD_MUTEX_INITIALIZER;

  pthread_create(&pid[0], NULL, be_call, NULL);
  pthread_create(&pid[1], NULL, call, NULL);

  while(!complete){
    sleep(1);
  }

  pthread_cancel(pid[0]);
  pthread_cancel(pid[1]);
  pthread_join(pid[0], NULL);
  pthread_join(pid[1], NULL);

  return 0;
}
