#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"


///////////////////////////////dcMatrix////////////////////////////////////
void dcmatrix(dcmat *mat, int r, int c){
	/*
	Initialise a dcmatrix

	Parameters
	----------
	mat: dcmat pointer
	r : int number of rows 
	c: int number of columns
	*/
	mat->data = (int**)calloc(r, sizeof(int*));
	for(int i=0; i<r; i++)
		mat->data[i] = (int*)calloc(c, sizeof(int));
	mat->r = r;
	mat->c = c;
}

dcmat dcmatadd(dcmat *mat1, dcmat *mat2){
	/*
	Adds two dcmatrices and returns the resultant dcmatrix

	Parameters
	----------
	mat1: dcmat pointer to first matrix
	mat2: dcmat pointer to second matrix

	Returns
	-------
	rmat: resultant matrix
	*/
	dcmat rmat;
	if((mat1->r != mat2->r) || (mat1->c != mat2->c)){
		//raise error and exit
		printf("DaiCyError: dcMatrix dimensions not compatible");
		exit(1);

	}
	rmat.r = mat1->r;
	rmat.c = mat1->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat1->data[i][j] + mat2->data[i][j];
	return rmat;
}

dcmat dcmatsub(dcmat *mat1, dcmat *mat2){
	/*
	Subtracts two dcmatrices and returns the resultant dcmatrix

	Parameters
	----------
	mat1: dcmat pointer to first matrix
	mat2: dcmat pointer to second matrix

	Returns
	-------
	rmat: resultant matrix
	*/
	dcmat rmat;
	if((mat1->r != mat2->r) || (mat1->c != mat2->c)){
		//raise error and exit
		printf("DaiCyError: dcMatrix dimensions not compatible");
		exit(1);
	}
	rmat.r = mat1->r;
	rmat.c = mat1->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat1->data[i][j] - mat2->data[i][j];
	return rmat;
} 

dcmat dcmatones(int r, int c){
	/*
	Returns a dcmatrix of ones

	Parameters
	----------
	r: int number of rows
	c: int number of columns

	Returns
	-------
	rmat: dcmat of ones of dimensions (r,c)
	*/
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = 1;
	return rmat;
}

dcmat dcmatzeros(int r, int c){
	/*
	Returns a dcmatrix of zeros

	Parameters
	----------
	r: int number of rows
	c: int number of columns

	Returns
	-------
	rmat: dcmat of zeros of dimensions (r,c)
	*/
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = 0;
	return rmat;
}

dcmat dcmatcopy(dcmat *mat){
	/*
	Returns a copy of the dcmatrix

	Parameters
	----------
	mat: dcmat pointer

	Returns
	-------
	rmat: copy of the given dcmatrix 
	*/
	dcmat rmat;
	rmat.r = mat->r;
	rmat.c = mat->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = mat->data[i][j];
	return rmat;
}

int dcmattrace(dcmat *mat){
	/*
	Returns trace of given square dcmatrix

	Parameters
	----------
	mat: dcmat pointer

	Returns
	-------
	trace: int value of the trace of the dcmatrix
	*/
	if(mat->r != mat->c){
		printf("DaiCyError: Trace not found. Matrix dimensions do not match.\n");
		exit(1);
	}
	int trace = 0;
	for(int i=0; i<mat->r; i++)
		for(int j=0; j<mat->c; j++)
			if(i==j)
				trace += mat->data[i][j];
	return trace;
}

void dcmatshow(dcmat *mat){
	/*
	Displays the dcmatrix

	Parameters
	----------
	mat: dcmat pointer
	*/
	for(int i=0; i<mat->r; i++){
		for(int j = 0; j<mat->c; j++){
			printf("%d ", mat->data[i][j]);
		}
		printf("\n");
		}
}

dcmat todcmat(int **a, int r, int c){
	/*
	Converts a given 2-D array into a dcmatrix

	Parameters
	----------
	a: pointer to 2-D int array
	r: int number of rows
	c: int number of columns

	Returns
	-------
	rmat: dcmatrix

	Note
	----
	Can do away with r and c fields by using sizeof
	*/
	dcmat rmat;
	rmat.r = r;
	rmat.c = c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			rmat.data[i][j] = a[i][j];
	return rmat;
}

dcmat dcmatmul(dcmat *mat1, dcmat *mat2){
	/*
	Multiplies two dcmatrices

	Parameters
	----------
	mat1: pointer to dcmat mat1
	mat2: pointer to dcmat mat2

	Returns
	-------
	rmat Resultant dcmatrix 
	*/
	if(mat1->c != mat2->r){
		//raise error and return
		printf("DaiCyError: dcMatrix dimensions not compatible");
		exit(1);
	}

	dcmat rmat;
	rmat.r = mat1->r;
	rmat.c = mat2->c;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<rmat.r; i++)
		for(int j=0; j<rmat.c; j++)
			for(int k = 0; k<mat1->c; k++)
				rmat.data[i][j] += mat1->data[i][k]*mat2->data[k][j];
	return rmat;
}

dcmat dcmattranspose(dcmat *mat){
	/*
	Returns the transpose of the given dcmatrix

	Parameter
	---------
	mat: pointer to dcmat

	Returns
	-------
	rmat: transpose of the dcmatrix
	*/
	dcmat rmat;
	rmat.r = mat->c;
	rmat.c = mat->r;
	rmat.data = (int**)calloc(rmat.r, sizeof(int*));
	for(int i=0; i<rmat.r; i++)
		rmat.data[i] = (int*)calloc(rmat.c, sizeof(int));
	for(int i=0; i<mat->r; i++){
		for(int j=0; j<mat->c; j++){
			rmat.data[j][i] = mat->data[i][j];
		}
	}
	return rmat;
}