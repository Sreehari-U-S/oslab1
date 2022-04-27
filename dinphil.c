#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t chopstick[5];
void eat(int ph)
{
	printf("Philosopher%d is eating\n",ph);
}

void *philos(void *arg)
{
	int ph = *(int *)arg;
	printf("Philosopher%d is trying to eat\n",ph);
	printf("Philosopher%d is trying to take the left chopstick\n",ph);
	sem_wait(&chopstick[ph]);    //int sem_wait(sem_t *sem);
	printf("Philosopher%d takes the left chopstick\n",ph);
	printf("Philosopher%d is trying to take the right chopstick\n",ph);
	sem_wait(&chopstick[(ph+1)%5]); 
	printf("Philosopher%d takes the right chopstick\n",ph);
	eat(ph);
	sleep(2);
	printf("Philosopher%d is trying to release the left chopstick\n",ph);
	sem_post(&chopstick[ph]);   //int sem_post(sem_t *sem);
	printf("Philosopher%d releases the left chopstick\n",ph);
	printf("Philosopher%d is trying to release the right chopstick\n",ph);
	sem_post(&chopstick[(ph+1)%5]); 
	printf("Philosopher%d releases the right chopstick\n",ph);
}

void main()
{
	int i,n[5];
	pthread_t T[5];
	for(i=0;i<5;i++)
	{
		sem_init(&chopstick[i],0,1);    // sem_init(sem_t *sem, int pshared, unsigned int value);
	}
	for(i=0;i<5;i++)
	{
		n[i]=i;
		pthread_create(&T[i],NULL,philos,(void *)&n[i]);  //  int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *),
                         							// void *restrict arg);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(T[i],NULL);  //int pthread_join(pthread_t thread, void **value_ptr);
	}
}
