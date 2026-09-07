#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_function(void *arg);

int mode = 1;
int thread_loop = 0;
int main_loop = 0;

int main()
{
	pthread_t thread1;
	
	pthread_create(&thread1, NULL, &thread_function, NULL);

	while(main_loop < 5)
	{
		if(mode == 1)
		{
			printf("Hello from main thread\n");
			mode = 2;
			main_loop++;
		}
		else
		{
			sleep(1);
		}
	}

	pthread_join(thread1,NULL);

	return 0;
}

void *thread_function(void *arg)
{
	while(thread_loop < 5)
	{
		if(mode == 2)
		{
			printf("Hello from thread1!\n");
			mode = 1;
			thread_loop++;
		}
		else
		{
			sleep(1);
		}
	}
	pthread_exit(NULL);
}
