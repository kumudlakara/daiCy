#include<stdio.h>
#include "daiCy.h"

int main(){

	dcstr s;
	dcstring(&s,"hello world");
	printf("After initializing dcstring:%s (%d)\n", s.data, s.length);
	printf("Char at %d: %c \n", 6, dccharAt(&s,6));
	printf("Num words:%d\n", dcnum_words(&s));
	dccapitalize(&s);
	printf("After capitalizing:%s\n", s.data);
	dcstr t;
	printf("before copy\n");
	t = dcstrcopy(&s);
	printf("After dcstrcopy: %s\n", t.data);
	dcstr p;
	dcstring(&p, "daiCy");
	dcstr c;
	c = dcstrconcat(&s, &p);
	printf("After concatenating:%s\n", c.data);
	printf("dcisupper: %d\n", dcisupper(&s));
	printf("dcislower: %d\n", dcislower(&s));
	dctoupper(&s);
	printf("After dctoupper: %s\n", s.data);
	dctolower(&s);
	printf("After dctolower: %s\n", s.data);
	dcstr substr = dcsubstr(&s, 0, 3);
	printf("After dcsubstr string is: %s\n", substr.data);
	printf("dcstrcmp: %d\n", dcstrcmp(&p, &s));
	char str[]="hello todc demo";
	dcstr z = todcstr(str);
	printf("After todcstr: %s\n", z.data);
	dcstrfree(&s);

}