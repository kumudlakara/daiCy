#define ARR_SIZE 100
#define DEFAULT_ORDER "ASC"

typedef struct dcArray{
	int capacity;
	int *data;
	int size;
}dcarr;


//intialize the array
void dcarray(dcarr*);
//expand the array to double the size
void dcexpand(dcarr*);
//append value to end of array
void dcappend(dcarr*, int value);
//free the memory allocated to array
void dcfree(dcarr*);
//set value at index
void dcset(dcarr*, int index, int value);
//get value at index
int dcget(dcarr*, int index);
//create a copy of array
dcarr dccopy(dcarr*);
//sort the array
void dcsort(dcarr*, char order[]);

