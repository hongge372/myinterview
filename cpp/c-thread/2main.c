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
    pthread_mutex_lock(&qlock);
    //    while(workq == NULL){
    if(intflg<1){
      printf("the queue is empty, i am going to sleep and release the mutex \n");
      pthread_cond_wait(&qready, &qlock);
    }
    intflg--;
    mp = workq;
    printf("the consume is--  %d , inflg(%d) \n", mp->val, intflg);
    workq = mp->next;
    pthread_mutex_unlock(&qlock);

  }
}

void enqueue_msg(struct msg* mp){

  mp->next = workq;
  workq = mp;
  //  printf("Thread 2 put message into  ...\n ");

}

void *thread1(void* arg){
  process_msg();
  return NULL;
}

void *thread2(void *arg){
  int i = 0;
  while(1){
    pthread_mutex_lock(&qlock);
    if(intflg>0){
      pthread_mutex_unlock(&qlock);
      continue;
    }
    //    sleep(5);
    struct msg* mp = (struct msg*)malloc(sizeof(struct msg));
    mp->next = NULL;
    mp->val = i;
    intflg++;
    printf("Thread 2 put message into, push %d  , intflg:= %d  ...\n ", i, intflg);
    i++;
    enqueue_msg(mp);
  pthread_cond_signal(&qready);
  pthread_mutex_unlock(&qlock);
  //  pthread_cond_signal(&qready);
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

