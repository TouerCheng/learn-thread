/*
 * =====================================================================================
 *
 *       Filename:  jointhread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2014 07:31:10 PM
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

void * help(void *arg)
{
printf("i do something to help");
sleep(3);
pthread_exit(0);
printf("dddddddddd");
}
int main(int argc, char *argv[])
{   
	printf("the main thid is run\n");

	pthread_t thid;
	int status;
	pthread_create(&thid,NULL,help,NULL);
	printf("create a new thread\n");//dsadsaddsa
	pthread_join(thid,(void *)&status);
	printf("the thread wait %d\n",status);
	
	return EXIT_SUCCESS;//dsdsdddsssaaasssdddsssaaassssssssssddddfdddddddddddaaaaddddsssss
}

