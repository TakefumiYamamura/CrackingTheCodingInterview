#include <iostream>
#include <vector>
#include <pthread.h>
#include <stdio.h>

const int data_num = 10;
const int thread_num = 2;

using namespace std;

typedef struct _thread_arg {
	int thread_no;
	int* data;
	pthread_mutex_t *mutex;
} thread_arg_t;


void thread_func(void *arg){
	thread_arg_t* thread = (thread_arg_t*)arg;
	for (int i = 0; i < data_num; ++i)
	{
		pthread_mutex_lock(thread->mutex);
		int result = thread->data[i] + 1;
		sched_yield();
		thread->data[i] = result;
		pthread_mutex_unlock(thread->mutex);
	}

}

int main(){
	vector<pthread_t> handle;
	handle.resize(thread_num);
	vector<thread_arg_t> targ;
	targ.resize(data_num);
	int data[10];
	for (int i = 0; i < data_num; ++i)
	{
		data[i] = 0;
	}
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	// create thread
	for (int i = 0; i < thread_num; ++i)
	{
		targ[i].thread_no = i;
		targ[i].data = data;
		targ[i].mutex = &mutex;
		pthread_create(&handle[i], NULL, (void *(*)(void *))thread_func, (void *)&targ[i]);
	}
	for (int i = 0; i < thread_num; ++i)
	{
		pthread_join(handle[i], NULL);
	}
	pthread_mutex_destroy(&mutex);

	for (int i = 0; i < data_num; ++i)
	{
		printf("data%d : %d\n", i, data[i]);
	}
	return 0;
}