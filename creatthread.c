/*
 * =====================================================================================
 *
 *       Filename:  creatthread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2014 06:02:04 PM
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
int* thread(void * arg)
{
pthread_t newthid;

newthid=pthread_self();
printf("this new thread ID = %u \n",newthid);
return NULL;
}
int main(int argc, char *argv[])
{

	pthread_t thid;
	printf("main thread ID = %u\n",pthread_self());
	if(pthread_create(&thid,NULL,(void*)thread,NULL)!=0)
	{
		printf("woor!");
		exit(1);
	}
	sleep(3);
	return 0;
}

