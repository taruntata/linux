#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t consumer, producer;

void *thread_producer(void *arg);
void *thread_consumer(void *arg);

char buff[26];
char temp[26];
pthread_mutex_t lock;

int main()
{
	pthread_mutex_init(&lock, NULL);

	pthread_create(&producer, NULL, thread_producer, NULL);
	pthread_create(&consumer, NULL, thread_consumer, NULL);

	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);

	return 0;
}

void *thread_producer(void *arg)
{
	while(1)
	{
		int in = 0;
		char ch = 'A';
		pthread_mutex_lock(&lock);
		for(int i = 0; i < 26; i++)
		{
			buff[in] = ch++;
			in = (in + 1) % 26;
		}
		printf("Producer = %s\n\t\t",buff);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

void *thread_consumer(void *arg)
{
	while(1)
	{
		int out = 0;
		pthread_mutex_lock(&lock);
		for(int i = 0; i < 26; i++)
		{
			temp[out] = buff[out];
			out = (out + 1) % 26;
		}
		printf("consumer = %s\n", temp);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

