/*
 * =====================================================================================
 *
 *       Filename:  tsd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2014 08:27:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cheng, 623977469@qq.com
 *        Company:  LinuxGroup2013
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_key_t key;

void * thread2(void * arg)
{
	int tsd=5;
	printf("thread %d is running\n",pthread_self());
	pthread_setspecific(key,(void *)tsd);
	printf("thread %d returns %d\n",pthread_self(),pthread_getspecific(key));
	sleep(3);
	//return;
}

void *thread1 (void *arg)
{
	int tsd=0;
	pthread_t thid2;

	printf("thread %d is running\n",pthread_self());
	pthread_setspecific(key,(void *)tsd);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(2);
	printf("thread %d retruns %d\n",pthread_self(),pthread_getspecific(key));
}
int main(int argc, char *argv[])
{

	pthread_t thid1;
	printf("start!\n");
	pthread_key_create(&key,NULL);
	pthread_create(&thid1,NULL,thread1,NULL);
	sleep(3);
	pthread_key_delete(key);
	printf("is over\n");
	return 0;
}

