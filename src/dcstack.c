#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


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

void dcshow_stack(dcstack *arr){
	for(int i = 0; i <= arr->top; i++){
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void dcfreestack(dcstack *arr){
	free(arr->data);
}
