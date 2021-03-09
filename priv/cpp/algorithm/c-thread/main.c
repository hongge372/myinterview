#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


struct msg{
  struct msg* next;
  int val;
};

static int intflg=0;
struct msg* workq = NULL;

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(){
  struct msg* mp;
  while(1){
    sleep(5);
    intflg--;
    pthread_mutex_lock(&qlock);
    while(workq == NULL){
      printf("the queue is empty, i am going to sleep and release the mutex \n");
      pthread_cond_wait(&qready, &qlock);
    }
    mp = workq;
    workq = mp->next;
    pthread_mutex_unlock(&qlock);
    printf("the consume is %d \n", mp->val);
  }
}

void enqueue_msg(struct msg* mp){
  pthread_mutex_lock(&qlock);
  intflg++;
  mp->next = workq;
  workq = mp;
  printf("Thread 2 put message into  ...\n ");
  pthread_mutex_unlock(&qlock);
  pthread_cond_signal(&qready);
}

void *thread1(void* arg){
  process_msg();
  return NULL;
}

void *thread2(void *arg){
  int i = 0;
  while(1){
    if(intflg>0){
      continue;
    }
    //    sleep(5);
    struct msg* mp = (struct msg*)malloc(sizeof(struct msg));
    mp->next = NULL;
    mp->val = i;
    i++;
    enqueue_msg(mp);
  }
  return NULL;
}

int main(){
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, thread1, NULL);
  pthread_create(&tid2, NULL, thread2, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
}

