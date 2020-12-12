#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "daiCy.h"

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
		printf("DaiCyError: Index: %d out of bounds. dcget failed!\n", index);
		
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

