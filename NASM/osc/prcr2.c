#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

#define maxterms 5
#define buffersize 5

sem_t empty,full;
int in=0,out=0,buffer[buffersize];
pthread_mutex_t mutex;

void main(){
	pthread_t pro[5],con[5];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,buffersize);
	sem_init(&full,0,0);
	

	pthread_create(&pro[i], NULL, (void *)producer, NULL);
	pthread_create(&con[i], NULL, (void *)consumer, NULL);
	pthread_join(pro[i], NULL);
	pthread_join(con[i], NULL);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}

void *producer(void *pro){
	int item;
		item=rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in]=item;
		printf("prod item %d at %d\n",buffer[in],in);
		in=(in+1)%buffersize;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
}

void *consumer(void *con){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item=buffer[out];
		printf("conr consd item %d from %d\n",buffer[out],out);
		out=(out+1)%buffersize;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
}
