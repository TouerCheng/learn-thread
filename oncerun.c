/*
 * =====================================================================================
 *
 *       Filename:  oncerun.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2014 06:31:30 PM
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

pthread_once_t once =1;
void run(void)
{
printf("Function run is runing in thread is %d\n",pthread_self());
}

void * thread1(void *arg)
{
pthread_t thid=pthread_self();
printf("thread 1 ID is %u \n",thid);
pthread_once(&once,run);
printf("thread1 end\n");
}
void * thread2(void *arg)
{
pthread_t thid=pthread_self();
printf("thread 2 ID is %u \n",thid);
pthread_once(&once,run);
printf("thread2 end\n");
}
int main(int argc, char *argv[])
{
	//printf("%d\n\n",PTHREAD_ONCE_INIT);
	pthread_t thid1,thid2;
	pthread_create(&thid1,NULL,thread1,NULL);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(3);
	printf("main thread exit!\n");
	return EXIT_SUCCESS;
}

