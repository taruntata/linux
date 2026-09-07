#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

pthread_t thread1, thread2;
int num = 1;

void *thread_function(void *);
//void *thread_function2(void *);

pthread_mutex_t lock;

int main()
{
	pthread_create(&thread1, NULL, thread_function, NULL);
	pthread_create(&thread2, NULL, thread_function, NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return 0;
}

void *thread_function(void *arg)
{
	for(int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&lock);
		printf("%d\n",num++);
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
}

