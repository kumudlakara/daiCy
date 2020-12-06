#define ARR_SIZE 100
#define DEFAULT_ORDER "ASC"
#define STACK_SIZE 100
#define QUEUE_SIZE 100

//struct for dcarray
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


//struct for dcstring
typedef struct dcString{
	char *data;
	int length;
}dcstr;

//initialize the string
void dcstring(dcstr*, char word[]);
//create a copy of the string
dcstr dcstrcopy(dcstr*);
//capitalize all first letters of string
void dccapitalize(dcstr*);
//return number of words in string
int dcnum_words(dcstr*);
//free allocated memory
void dcstrfree(dcstr*);
//return character at index
char dccharAt(dcstr*, int index);
//concatenate two strings
dcstr dcstrconcat(dcstr*, dcstr*);


//struct for dcfarray
typedef struct dcfArray{
	int capacity;
	float *data;
	int size;
}dcfarr;


//intialize the array
void dcfarray(dcfarr*);
//expand the array to double the size
void dcfexpand(dcfarr*);
//append value to end of array
void dcfappend(dcfarr*, float value);
//free the memory allocated to array
void dcffree(dcfarr*);
//set value at index
void dcfset(dcfarr*, int index, float value);
//get value at index
float dcfget(dcfarr*, int index);
//create a copy of array
dcfarr dcfcopy(dcfarr*);
//sort the array
void dcfsort(dcfarr*, char order[]);


//struct for dcstacks
typedef struct dcStack{
	int top;
	int *data;
	int capacity;
	int size;
}dcstack;

//initialize the dcstack
void dcstack_init(dcstack*);
//push into dcstack
void dcpush(dcstack*, int);
//pop element from stack
int dcpop(dcstack*);
//display the stack
void dcshow_stack(dcstack*);
//free the memoray allocated to the stack
void dcfreestack(dcstack*);


//struct for dcqueue
typedef struct dcQueue{
	int front;
	int rear;
	int capacity;
	int *data;
}dcqueue;

//initialize the dcqueue
void dcqueue_init(dcqueue*);
//enqueue an element into dcqueue
void dcenq(dcqueue*, int);
//dequeue an element from the dcqueue
int dcdeq(dcqueue*);
//display content of te queue
void dcshow_queue(dcqueue*);
//free the memory allocated to the queue
void dcfreequeue(dcqueue*);
