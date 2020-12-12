#include<stdio.h>
#include "daiCy.h"

int main(){
	
	dcarr a;
	dcarray(&a);
	printf("array initialized\n");
	dcappend(&a,4);
	dcappend(&a,6);
	dcappend(&a,9);
	printf("after dcappend\n");
	for(int i = 0; i<a.size; i++){
		printf("%d ",a.data[i]);
	}
	printf("\n");
	dcsort(&a, "DESC");
	printf("after dcsort\n");
	for(int i = 0; i<a.size; i++){
		printf("%d ",a.data[i]);
	}
	printf("\n");
	dcset(&a, 1, 3);
	printf("after dcset\n");
	for(int i = 0; i<a.size; i++){
		printf("%d ",a.data[i]);
	}
	printf("\n");
	printf("dcget test: %d\n", dcget(&a,2));
	dcarr b;
	b = dccopy(&a);
	printf("after dccopy\n");
	for(int i = 0; i<b.size; i++){
		printf("%d ",b.data[i]);
	}

	printf("\n");
	dcexpand(&a);

}
