#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<vector>

using namespace std;

mutex mut;
condition_variable empty, full;
queue<int> Q;
int flag;
bool over = false;

void conduct(int num, int count)
{
  for(int i=0; i<num; i++){
    unique_lock<mutex>lk(mut);
    empty.wait(lk);
    Q.push(i);
    flag = i % count;
    full.notify_all();
    lk.unlock();
  }
  over = true;
}

void consumer(int id, int count)
{
  while(true)
    {
      unique_lock<mutex> lk(mut);
      full.wait(lk, [&](){return flag == id;});

      if(!Q.empty()){
	int i = Q.front();
	Q.pop();
	cout<<"thread" << id << "get " << i << endl;
      }
      if(over){
	break;
      }
      empty.notify_one();
    }

  flag = (id == count-1 ? 0 : id+1 );
  full.notify_all();
}

int main(int argc, char*argv[])
{
  int count;
  int num;
  vector<thread> threads;
  num = 10;
  count = 3;

  thread t1(conduct, num, count);
  for(int i=0; i< count; i++){
    threads.push_back(thread(consumer, i, count));
  }
  t1.join();
  for(auto &t:threads){
    t.join();
  }

  return 0;
}
