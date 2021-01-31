#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


///////////////////////////////dcfArray////////////////////////////////////

void dcfarray(dcfarr *arr){
	/*
	Initializes the dcfarray

	Parameters
	----------
	arr : dcarr pointer
	*/
	arr->capacity = ARR_SIZE;
	arr->size = 0;
	arr->data = (float*)malloc(sizeof(float)*arr->capacity);
}

void dcfexpand(dcfarr *arr){
	/*
	Expands dcfarry capacity when an overflow occurs.
	Expands to twice the initial capacity.

	Parameters
	----------
	arr: dcfarr pointer
	*/
	if(arr->size >= arr->capacity){
	arr->capacity *= 2;
	arr->data = (float*)realloc(arr->data, sizeof(float)*arr->capacity);
	}
}

void dcfappend(dcfarr *arr, float value){
	/*
	Adds an element to the end of the dcfarray

	Parameters
	----------
	arr: dcfarr pointer
	value : float value to append to array
	*/
	dcfexpand(arr);
    arr->data[(arr->size)++] = value;
}

void dcffree(dcfarr *arr){
	/*
	Frees the dcfarray memory

	Parameters
	----------
	arr: dcfarr pointer
	*/
	free(arr->data);
}

void dcfset(dcfarr *arr, int index, float value){
	/*
	Sets value at particular index position

	Parameters
	----------
	arr: dcfarr pointer
	index: int index value
	value: float value to set at index position of dcfarray
	*/
	dcfexpand(arr);
	if(index <= arr->size-1 && index>=0){
		arr->data[index] = value;
	}
	else{
		//raise warning/error
		printf("DaiCyError: Index: %d out of bounds\ndcset failed!\n", index);
		exit(1);
	}
}

float dcfget(dcfarr *arr, int index){
	/*
	Gets value at a particular index

	Parameters
	----------
	arr: dcfarr pointer
	index: int index value to get value in array at that position

	Returns
	-------
	arr->data[index]: float value at index
	*/
	if(index >= arr->size || index < 0){
		//raise error/warning
		printf("DaiCyError: Index: %d out of bounds. dcget failed!\n", index);
		
	}
	return arr->data[index];
}

dcfarr dcfcopy(dcfarr *arr){
	/*
	Returns copy of dcfarray

	Parameters
	----------
	arr: dcfarr pointer

	Returns
	-------
	copy of dcfarr
	*/
	dcfarr temp;
	temp.data = arr->data;
	temp.size = arr->size;
	temp.capacity = arr->capacity;
	return temp;
}

void swapf(float *a, float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

int partition_ascf(float *a, int low, int high){
	int pivot;
	pivot = a[high];
	int i = low - 1;
	int j;
	for(j = low; j<=high-1; j++){
		if(a[j] < pivot){
			i++;
			swapf(&a[j], &a[i]);
		}
	}
	swapf(&a[i+1], &a[high]);
	return i+1;
}

void quicksort_ascf(float *a, int low, int high){
	int pivot;
	if(low < high){
		pivot = partition_ascf(a, low, high);
		quicksort_ascf(a, low, pivot-1);
		quicksort_ascf(a, pivot+1, high);
	}	

}

int partition_descf(float *a, int low, int high){
	int pivot;
	pivot = a[high];
	int i = low - 1;
	int j;
	for(j = low; j<=high-1; j++){
		if(a[j] > pivot){
			i++;
			swapf(&a[j], &a[i]);
		}
	}
	swapf(&a[i+1], &a[high]);
	return i+1;
}

void quicksort_descf(float *a, int low, int high){
	int pivot;
	if(low < high){
		pivot = partition_descf(a, low, high);
		quicksort_descf(a, low, pivot-1);
		quicksort_descf(a, pivot+1, high);
	}	

}

void dcfsort(dcfarr *arr, char order[]){
	/*
	Sorts the dcfarray inplace in ascending or descending order.

	Parameters
	----------
	arr: dcfarr pointer
	order: string to decide sorting order
	*/
	if(!strcmp(order,"ASC")){
		//sort in asc order
		quicksort_ascf(arr->data,0, arr->size);

	}
	else if(!strcmp(order,"DESC")){
		//sort in desc order
		quicksort_descf(arr->data,0,arr->size);
	}
	else{
		//raise error/warning
		printf("DaiCyError: dcsort argument[1] mismatch. Make sure argument[1] = ASC or argument[1] = DSC\n");
		printf("Unable to sort array\n");
		return;
	}
}

dcfarr todcfarr(float arr[], int size){
	dcfarr retarr;
	dcfarray(&retarr);
	retarr.size = size;
	for(int i=0; i<retarr.size; i++){
		retarr.data[i] = arr[i];
	}
	return retarr;
}

void dcswapfarr(dcfarr *arr, int i, int j){
	if(i >= arr->size || j >= arr->size){
		printf("DaiCyError: array index out of bounds. ");
		printf("Unable to swap array elements.\n");
		return;
	}

	float temp = arr->data[i];
	arr->data[i] = arr->data[j];
	arr->data[j] = temp;
}