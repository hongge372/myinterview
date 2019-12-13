#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct node{
  int n_number;
  struct node *n_next;
}*head = NULL;

static void cleanup_handler(void *arg)
{
  printf("Cleanup handler of second thread. \n");
  free(arg);
  pthread_mutex_unlock(&mtx);
}

static void *thread_func(void *arg)
{
  struct node *p = NULL;
  pthread_cleanup_push(cleanup_handler, p);
  while(1)
    {
      pthread_mutex_lock(&mtx);
      while(head == NULL)
	{
	  pthread_cond_wait(&cond, &mtx);
	  p=head;
	  head=head->n_next;
	  printf("Got %d from front of queue \n", p->n_number);
	  free(p);
	}
      pthread_mutex_unlock(&mtx); 
    }
  pthread_cleanup_pop(0);
}

int main(int argc, char* argv[])
{
  pthread_t tid;
  int i;
  struct node *p;

  pthread_create(&tid, NULL, thread_func, NULL);
  sleep(1);

  for(i=0; i<10; i++)
    {
      p=(struct node*)malloc(sizeof(struct node));
      p->n_number=i;
      pthread_mutex_lock(&mtx);
      p->n_next=head;
      head=p;
      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mtx);
      sleep(1);
    }
  printf("thread 1 wana end the line.  cancel thread 2 n");

  pthread_cancel(tid);
  pthread_join(tid, NULL);
  printf("All done --exitting \n");
  return 0;
}
