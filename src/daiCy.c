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
		printf("FATAL ERROR! Index: %d out of bounds\ndcset failed!\n", index);
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
		printf("FATAL ERROR! Index: %d out of bounds. dcget failed!\n", index);
		
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
		printf("ERROR: dcsort argument[1] mismatch. Make sure argument[1] = ASC or argument[1] = DSC\n");
		printf("Unable to sort array\n");
		return;
	}
}


///////////////////////////////dcString////////////////////////////////////

void dcstring(dcstr *str, char word[]){
	/*
	Initializes the dcstr

	Parameters
	----------
	str : dcstr pointer
	*/
	//str->data = (char*)malloc(sizeof(char)*(strlen(word)+1));
	str->data = strdup(word);
	str->length = strlen(word)+1;
}

dcstr dcstrcopy(dcstr *str){
	/*
	Returns copy of dcstring

	Parameters
	----------
	str: dcstr pointer

	Returns
	-------
	copy of dcstr
	*/
	dcstr temp;
	strcpy(temp.data,str->data);
	temp.length = str->length;
	return temp;
}

void dcstrfree(dcstr *str){
	/*
	Frees the string memory

	Parameters
	----------
	str: dcstr pointer
	*/
	free(str->data);
}

char dccharAt(dcstr *str, int index){
	/*
	Returns value at a particular index

	Parameters
	----------
	str: dcstr pointer
	index: int index value to get value in string at that position

	Returns
	-------
	str->data[index]: char value at index
	*/
	if(index >= str->length || index < 0){
		//raise error/warning
		printf("FATAL ERROR! Index: %d out of bounds. dcget failed!\n", index);
		
	}
	return str->data[index];
}

dcstr dcstrconcat(dcstr *str1, dcstr *str2){
	/*
	Returns a concatenated dcstring containing str1+str2

	Parameters
	----------
	str1: dcstr pointer
	str2: dcstr pointer

	Returns
	-------
	temp: concatenated dcstring
	*/
	int i, k = 0;
	dcstr temp;
	//temp.data = (char*)malloc(sizeof(char)*(str1->length + str2->length) + 1);
	temp.data = strdup(str1->data);
	temp.length = str1->length + str2->length + 1;
	for(i = str1->length-1; k<str2->length; i++,k++){
		temp.data[i] = str2->data[k];
	}
	temp.data[i] = '\0';
	return temp;
}

int dcnum_words(dcstr *str){
	/*
	Returns the number of words in the dcstring

	Parameters
	----------
	str: dcstr pointer

	Returns
	-------
	count: number of words in the dcstring
	*/
	if(!strcmp(str->data," "))
		return 0;
	int count = 1;
	for(int i=0;i<str->length; i++){
		if(str->data[i] == ' ' && str->data[i-1] != ' '){
			count++;
		}
	}
	return count;
}

void dccapitalize(dcstr *str){
	/*
	Capitalizes the first letter of each word in the dcstring

	Parameters
	----------
	str: dcstr pointer

	*/
	str->data[0] = toupper(str->data[0]);
	for(int i=1;i<str->length; i++){
		if((str->data[i] == ' ') && (str->data[i-1] != ' ')){
			str->data[i+1] = toupper(str->data[i+1]);
		}
	}
}


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
		printf("FATAL ERROR! Index: %d out of bounds\ndcset failed!\n", index);
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
		printf("FATAL ERROR! Index: %d out of bounds. dcget failed!\n", index);
		
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
		printf("ERROR: dcsort argument[1] mismatch. Make sure argument[1] = ASC or argument[1] = DSC\n");
		printf("Unable to sort array\n");
		return;
	}
}


///////////////////////////////dcStack////////////////////////////////////
void dcstack_init(dcstack* arr){
	arr->data = (int*)malloc(sizeof(int)*STACK_SIZE);
	arr->capacity = STACK_SIZE;
	arr->size = 0;
	arr->top = -1;
}

void dcpush(dcstack* arr, int value){
	if(arr->top < arr->capacity){
	arr->data[++(arr->top)] = value;
	arr->size++;
	}
	else{
		//raise overflow error
		printf("DaiCyError: Stack Overflow!");
		exit(1);
	}
}

int dcpop(dcstack *arr){
	if(arr->top < 0){
		//raise underflow error
		printf("DaiCyError: Stack Underflow!");
		exit(1);
	}
	return arr->data[(arr->top)--];
}

void dcfreestack(dcstack *arr){
	free(arr->data);
}
