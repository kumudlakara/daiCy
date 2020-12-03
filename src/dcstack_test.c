#include<stdio.h>
#include "daiCy.h"

int main(){
	
	dcstack s;
	dcstack_init(&s);
	//to check for underflow
	//dcpop(&s);
	printf("After intializing the stack\n");
	dcpush(&s,3);
	dcpush(&s,4);
	dcpush(&s,5);
	printf("After dcpush\n");
	for(int i = 0; i<=s.top; i++){
		printf("%d ", s.data[i]);
	}
	printf("\n");
	printf("After dcpop: %d\n", dcpop(&s));
	for(int i = 0; i<=s.top; i++){
		printf("%d ", s.data[i]);
	}
	printf("\n");
	dcfreestack(&s);

}
