#include<stdio.h>
#include "daiCy.h"
#include<stdlib.h>

int main(){
	
	dcmat m, n;
	dcmatrix(&m, 3, 4);
	printf("after dcmatrix initialization:\n");
	//dcmatshow(&m);
	n = dcmatones(3,4);
	printf("initialization using dcmatones:\n");
	dcmatshow(&n);
	dcmat s;
	s = dcmatadd(&m, &n);
	printf("After dcmatadd:\n");
	dcmatshow(&s);
	dcmat d;
	dcmat z;
	z = dcmatzeros(3,4);
	printf("after using dcmatzeros:\n");
	dcmatshow(&z);
	d = dcmatsub(&m, &n);
	printf("after dcmatsub:\n");
	dcmatshow(&d);
	printf("dcmattrace: %d\n", dcmattrace(&m));
	dcmat p;
	dcmatrix(&p, 4, 2);
	p = dcmatmul(&m , &p);
	printf("after dcmatmul:\n");
	dcmatshow(&p);
	int **a;
	a = (int**)calloc(3, sizeof(int*));
	for(int i=0; i<3; i++)
		a[i] = (int*)calloc(3, sizeof(int));
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			a[i][j] = 3;
	dcmat t;
	t = todcmat(a, 2, 3);
	printf("after converting to dcmat:\n");
	dcmatshow(&t);
}