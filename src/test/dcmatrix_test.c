#include<stdio.h>
#include "daiCy.h"
#include<stdlib.h>

int main(){
	
	dcmat m, n;
	dcmatrix(&m, 3, 4);
	printf("after dcmatrix initialization:\n");
	for(int i=0; i<m.r; i++)
		for(int j=0; j<m.c; j++)
			m.data[i][j] = j;
	dcmatshow(&m);
	n = dcmatones(4,4);
	printf("initialization using dcmatones:\n");
	dcmatshow(&n);
	dcmat s;
	printf("before dcmatadd");
	s = dcmatadd(&n, &n);
	printf("After dcmatadd:\n");
	dcmatshow(&s);
	dcmat d;
	dcmat z;
	z = dcmatzeros(3,4);
	printf("after using dcmatzeros:\n");
	dcmatshow(&z);
	d = dcmatsub(&z, &n);
	printf("after dcmatsub:\n");
	dcmatshow(&d);
	printf("dcmattrace: %d\n", dcmattrace(&n));
	dcmat p;
	//dcmatrix(&p, 4, 2);
	p = dcmatmul(&m , &n);
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
	t = todcmat(a, 3, 3);
	printf("after converting to dcmat:\n");
	dcmatshow(&t);
	dcmat tr;
	tr = dcmattranspose(&m);
	printf("after dcmatttranspose:\n");
	dcmatshow(&tr);
}