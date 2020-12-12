#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


///////////////////////////////dcQueue////////////////////////////////////

void dcqueue_init(dcqueue *arr){
	/*
	Initializes the dcqueue

	Parameters
	----------
	arr : dcqueue pointer
	*/
	arr->capacity = QUEUE_SIZE;
	arr->data = (int*)malloc(sizeof(int)*arr->capacity);
	arr->front = -1;
	arr->rear = -1;
}

void dcenq(dcqueue *arr, int value){
	/*
	Adds an element to the end of the dcqueue

	Parameters
	----------
	arr: dcqueue pointer
	value: int value to enqueue
	*/
	if(((arr->rear == arr->capacity - 1) && (arr->front == 0)) || (arr->rear == arr->front - 1))
	{
		//raise overflow warning
		printf("DaiCyError: Queue Overflow!\n");
		exit(1);
	}

	else if(arr->front == -1 && arr->rear == -1)
	{
		arr->data[++(arr->rear)] = value;
		arr->front = arr->rear;
	}

	else if( arr->front != 0 && arr->rear == arr->capacity-1)
	{
		arr->rear = 0;
		arr->data[arr->rear] = value;
	}
	else
	{
		arr->data[++(arr->rear)] = value;
	}	
}

int dcdeq(dcqueue *arr){
	/*
	Removes an element from front of dcqueue

	Parameters
	----------
	arr: dcqueue pointer

	Returns
	-------
	Int value from front of dcqueue
	*/
	int temp;
	if(arr->front == -1 && arr->rear == -1)
	{
		//raise underflow warning
		printf("DaiCyError: Queue Underflow!\n");
		exit(1);
	}

	else if(arr->front == arr->rear)
	{	temp = arr->front;
		arr->front = -1;
		arr->rear = -1;
		return arr->data[temp];
	}

	else if(arr->front == arr->capacity - 1 && arr->rear < arr->front)
	{
		temp = arr->front;
		arr->front = 0;
		return arr->data[temp];
	}

	else
	{	temp = arr->front;
		(arr->front)++;
		return arr->data[temp];
	}

}

void dcshow_queue(dcqueue *arr){
	/*
	Displays the dcqueue contents

	Parameters
	----------
	arr: dcqueue pointer
	*/
	if(arr->front <= arr->rear)
	{
		for(int i = arr->front; i <= arr->rear; i++)
		{
			printf("%d ", arr->data[i]);
		}
		printf("\n");
	}

	if(arr->front > arr->rear)
	{
		for(int i = arr->front; i < arr->capacity; i++)
		{
			printf("%d ", arr->data[i]);
		}
		for(int i = 0; i <= arr->rear ; i++)
		{
			printf("%d ", arr->data[i]);
		}
		printf("\n");
	}
}

void dcfreequeue(dcqueue *arr){
	/*
	Frees memory allocated to dcqueue

	Parameters
	----------
	arr: dcqueue pointer
	*/
	free(arr->data);
}
