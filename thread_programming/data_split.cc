#include <iostream>
#include <vector>
#include <pthread.h>
#include <stdio.h>

const int data_num = 10;
const int thread_num = 2;
const int split_data_num = data_num/thread_num;

using namespace std;

typedef struct _thread_arg {
	int thread_no;
	int* data;
} thread_arg_t;


void thread_func(void *arg){
	thread_arg_t* thread = (thread_arg_t*)arg;
	for (int i = 0; i < split_data_num; ++i)
	{
		// cout << "thread" << thread->thread_no << " : " << thread->data[i] << endl;
		printf("thread%d : %d + 1 = %d\n",thread->thread_no, thread->data[i], thread->data[i]+1);
	}
}

int main(){
	vector<pthread_t> handle;
	handle.resize(thread_num);
	vector<thread_arg_t> targ;
	targ.resize(data_num);
	vector<int> data;
	for (int i = 0; i < data_num; ++i)
	{
		data.push_back(i);
	}

	// create thread
	for (int i = 0; i < thread_num; ++i)
	{
		targ[i].thread_no = i;
		targ[i].data = &data[split_data_num * i];
		pthread_create(&handle[i], NULL, (void *(*)(void *))thread_func, (void *)&targ[i]);
	}

	for (int i = 0; i < thread_num; ++i)
	{
		pthread_join(handle[i], NULL);
	}
	return 0;
}