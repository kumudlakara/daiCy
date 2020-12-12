#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


///////////////////////////////dcArray////////////////////////////////////

void dcarray(dcarr *arr){
	/*
	Initializes the dcarray

	Parameters
	----------
	arr : dcarr pointer
	*/
	arr->capacity = ARR_SIZE;
	arr->size = 0;
	arr->data = (int*)malloc(sizeof(int)*arr->capacity);
}

void dcexpand(dcarr *arr){
	/*
	Expands dcarry capacity when an overflow occurs.
	Expands to twice the initial capacity.

	Parameters
	----------
	arr: dcarr pointer
	*/
	if(arr->size >= arr->capacity){
	arr->capacity *= 2;
	arr->data = (int*)realloc(arr->data, sizeof(int)*arr->capacity);
	}
}

void dcappend(dcarr *arr, int value){
	/*
	Adds an element to the end of the dcarray

	Parameters
	----------
	arr: dcarr pointer
	value : int value to append to array
	*/
	dcexpand(arr);
    arr->data[(arr->size)++] = value;
}

void dcfree(dcarr *arr){
	/*
	Frees the array memory

	Parameters
	----------
	arr: dcarr pointer
	*/
	free(arr->data);
}

void dcset(dcarr *arr, int index, int value){
	/*
	Sets value at particular index position

	Parameters
	----------
	arr: dcarr pointer
	index: int index value
	value: int value to set at index position of dcarray
	*/
	dcexpand(arr);
	if(index <= arr->size-1 && index>=0){
		arr->data[index] = value;
	}
	else{
		//raise warning/error
		printf("DaiCyError: Index: %d out of bounds\ndcset failed!\n", index);
		exit(1);
	}
}

int dcget(dcarr *arr, int index){
	/*
	Gets value at a particular index

	Parameters
	----------
	arr: dcarr pointer
	index: int index value to get value in array at that position

	Returns
	-------
	arr->data[index]: int value at index
	*/
	if(index >= arr->size || index < 0){
		//raise error/warning
		printf("DaicyError: Index: %d out of bounds. dcget failed!\n", index);
		
	}
	return arr->data[index];
}

dcarr dccopy(dcarr *arr){
	/*
	Returns copy of dcarray

	Parameters
	----------
	arr: dcarr pointer

	Returns
	-------
	copy of dcarr
	*/
	dcarr temp;
	temp.data = arr->data;
	temp.size = arr->size;
	temp.capacity = arr->capacity;
	return temp;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition_asc(int *a, int low, int high){
	int pivot;
	pivot = a[high];
	int i = low - 1;
	int j;
	for(j = low; j<=high-1; j++){
		if(a[j] < pivot){
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[i+1], &a[high]);
	return i+1;
}

void quicksort_asc(int *a, int low, int high){
	int pivot;
	if(low < high){
		pivot = partition_asc(a, low, high);
		quicksort_asc(a, low, pivot-1);
		quicksort_asc(a, pivot+1, high);
	}	

}

int partition_desc(int *a, int low, int high){
	int pivot;
	pivot = a[high];
	int i = low - 1;
	int j;
	for(j = low; j<=high-1; j++){
		if(a[j] > pivot){
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[i+1], &a[high]);
	return i+1;
}

void quicksort_desc(int *a, int low, int high){
	int pivot;
	if(low < high){
		pivot = partition_desc(a, low, high);
		quicksort_desc(a, low, pivot-1);
		quicksort_desc(a, pivot+1, high);
	}	

}

void dcsort(dcarr *arr, char order[]){
	/*
	Sorts the dcarray inplace in ascending or descending order.

	Parameters
	----------
	arr: dcarr pointer
	order: string to decide sorting order
	*/
	if(!strcmp(order,"ASC")){
		//sort in asc order
		quicksort_asc(arr->data,0, arr->size);

	}
	else if(!strcmp(order,"DESC")){
		//sort in desc order
		quicksort_desc(arr->data,0,arr->size);
	}
	else{
		//raise error/warning
		printf("DaiCyError: dcsort argument[1] mismatch. Make sure argument[1] = ASC or argument[1] = DSC\n");
		printf("Unable to sort array\n");
		return;
	}
}

