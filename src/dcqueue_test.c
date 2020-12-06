#include<stdio.h>
#include "daiCy.h"

int main(){
	
	dcqueue q;
	dcqueue_init(&q);
	printf("After dcqueue_init\n");
	dcenq(&q, 3);
	dcenq(&q, 4);
	dcenq(&q, 5);
	printf("After dcenqueue:\n");
	dcshow_queue(&q);
	dcdeq(&q);
	printf("After dcdeq:\n");
	dcshow_queue(&q);
	dcfreequeue(&q);

}