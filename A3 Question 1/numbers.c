#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUM_THREADS 3

// Assingment 3, Question 1
// Kurtis Johnson & Abdullah Fasih
// Reference: Page 198+
// Use "gcc -pthread -o calcNums numbers.c" to compile in linux

/* Threads call these functions, these are declarations */
void *runAvg(void *param); 
void *runMin(void *param); 
void *runMax(void *param); 

/* Global Variables are shared by the threads */
int argCount,avg,max,min;

int main (int argc, char *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "Error, Needs missing aguments, Try ./calcNums 1 2 3 \n");
		exit(0);
	}
	
	argCount = argc - 1;
	int args[argCount];
	
	for(int i = 0; i < argCount ; i++) // 
	{
		if (argv[i + 1] < 0) //Checks each argument for negative values;
		{
			fprintf(stderr,"Error! Agruments cannot be negative \n");
			exit(0);
		}
		else
		{
			args[i] = atoi(argv[i + 1]); //Placing all arguments in an array to be passed to each thread.
		}
	}
	pthread_t tid[NUM_THREADS]; //The thread identifiers
	pthread_attr_t attr; //Default set of thread attrbutes
	pthread_attr_init(&attr); //Get the default attributes 
	pthread_create(&tid[0],&attr,runAvg,&args); //Create the thread for avg calculation
	pthread_create(&tid[1],&attr,runMin,&args); //Create the thread for min calculation
	pthread_create(&tid[2],&attr,runMax,&args); //Create the thread for max calculation

	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(tid[i],NULL); //Waits until all threads are done 
	}
	printf("%d is the average of the numbers provided \n", avg);
	printf("%d is the minimum number \n", min);
	printf("%d is the maximum number \n", max);	
}

//This thread will calculate average
void *runAvg(void *param)
{
	int *num = (int *) param; //Parse from void to int
	int sum = 0;
	for(int i = 0; i < argCount; i++)
	{
		sum += num[i];
	}
	avg = sum / argCount;
	pthread_exit(0); //Ends thread, can be used to return a value
}

//This thread will calculate the minimum
void *runMin(void *param)
{
	int *num = (int *) param;
	min = num[0];
	for(int i = 0; i < argCount; i++)
	{
		if (min > num[i])
		{
			min = num[i];
		}
	}
	pthread_exit(0); 
}

//This thread will calculate the maximum
void *runMax(void *param)
{
	int *num = (int *) param;
	max = num[0];
	for(int i = 0; i < argCount; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
	}
	pthread_exit(0);
}