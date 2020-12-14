#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


///////////////////////////////dcMatrix////////////////////////////////////
void dcmatrix(dcmat *mat, int r, int c){
	mat->data = (int**)calloc(r, sizeof(int*));
	for(int i=0; i<c; i++)
		mat->data[i] = (int*)calloc(c, sizeof(int));
}

dcmat dcmatadd(dcmat *mat1, dcmat *mat2){
	dcmat rmat;
	if((mat1->r != mat2->r) || (mat1->c != mat2->c)){
		//raise error and exit
	}
	rmat.r = mat1->r;
	rmat.c = mat1->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat1->data[i][j] + mat2->data[i][j];
	return rmat;
}

dcmat dcmatsub(dcmat *mat1, dcmat *mat2){
	dcmat rmat;
	if((mat1->r != mat2->r) || (mat1->c != mat2->c)){
		//raise error and exit
	}
	rmat.r = mat1->r;
	rmat.c = mat1->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat1->data[i][j] - mat2->data[i][j];
	return rmat;
} 

dcmat dcmatones(int r, int c){
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = 1;
	return rmat;
}

dcmat dcmatzeros(int r, int c){
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = 0;
	return rmat;
}

dcmat dcmatcopy(dcmat *mat){
	dcmat rmat;
	rmat.r = mat->r;
	rmat.c = mat->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat->data[i][j];
	return rmat;
}

int dcmattrace(dcmat *mat){
	int trace = 0;
	for(int i=0; i<mat->r; i++)
		for(int j=0; j<mat->c; j++)
			if(i==j)
				trace += mat->data[i][j];
	return trace;
}

void dcmatshow(dcmat *mat){
	for(int i=0; i<mat->r; i++){
		for(int j = 0; j<mat->c; j++){
			printf("%d ", mat->data[i][j]);
		}
		printf("\n");
		}
}

dcmat todcmat(int **a, int r, int c){
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = a[i][j];
	return rmat;
}

dcmat dcmatmul(dcmat *mat1, dcmat *mat2){
	if(mat1->c != mat2->r){
		//raise error and return
	}

	dcmat rmat;
	rmat.r = mat1->r;
	rmat.c = mat2->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.c; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			for(int k = 0; k<mat1->c; k++)
				rmat.data[i][j] += mat1->data[i][k]*mat2->data[k][j];
	return rmat;
}