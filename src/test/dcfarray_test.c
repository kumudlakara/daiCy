#include<stdio.h>
#include "daiCy.h"

int main(){
	
	dcfarr a;
	dcfarray(&a);
	printf("array initialized\n");
	dcfappend(&a,4.25);
	dcfappend(&a,6.32);
	dcfappend(&a,9.78);
	printf("after dcfappend\n");
	for(int i = 0; i<a.size; i++){
		printf("%f ",a.data[i]);
	}
	printf("\n");
	dcfsort(&a, "DESC");
	printf("after dcfsort\n");
	for(int i = 0; i<a.size; i++){
		printf("%f ",a.data[i]);
	}
	printf("\n");
	dcfset(&a, 1, 3.96);
	printf("after dcfset\n");
	for(int i = 0; i<a.size; i++){
		printf("%f ",a.data[i]);
	}
	printf("\n");
	printf("dcfget test: %f\n", dcfget(&a,2));
	dcfarr b;
	b = dcfcopy(&a);
	printf("after dcfcopy\n");
	for(int i = 0; i<b.size; i++){
		printf("%f ",b.data[i]);
	}
	printf("\n");
	float t[4] = {1.23,2.56,3.789,4.88};
	dcfarr q = todcfarr(t, 4);
	printf("after todcfarr\n");
	for(int i = 0; i<q.size; i++){
		printf("%f ",q.data[i]);
	}

	printf("\n");
	dcfexpand(&a);

}
