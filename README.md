# DaiCy :blossom: 
C library for Linux

DaiCy introduces enhanced features for the C language such as automatic array size expansion, dcstring datatype, dcmatrix datatype and much more. Each DaiCy datatype makes coding in the C language much more convinient by introducing functionality such as sorting, reversing, string manipulation etc. DaiCy aims to bridge the gap between C and the modern day programming languages. 

What follows are the DaiCy datatypes and some of the important functions associated with them:


# DaiCy datatypes:
 ## 1. DaiCy Array (dcarr)
 
 dcarrays have all the properties of vanilla arrays in C. In addition however, they support automatic memory allocation when the size of the array increases.
 
 ### Important Functions
 
 - `void dcexpand(dcarr *arr)` : automatic memory expansion on overflow.
 - `void dcappend(dcarr *arr, int value)` : add an element to the end of the dcarray.
 - `void dcset(dcarr *arr, int index, int value)` : set a particular value at the given index
 - `int dcget(dcarr *arr, int index)` : get the value at the index
 - `dcarr dccopy(dcarr *arr)` : create a copy of the dcarray
 - `void dcsort(dcarr *arr, char *order)` : sort the dcarray in  ascending or descending order. DaiCy uses quick sort for all sorting functions given its favourable time complexity.
 - `dcarr todcarr(int arr[], int size)` : convert vanilla C array to dcarray so as to make use of all advantages of dcarray.
 
  #### Recently added
  - `void dcswaparr(dcarr*, int, int)`
 
 #### To add
 - `dcarr dcresizearr(dcarr *arr)`
 
 *note: the "todc" property has not been added for all datatypes as of now: dcarray, dcfarray and dcmatrix*
 
 
 ## 2. DaiCy FloatArray (dcfarr)
 
 dcfarrays have all the properties of vanilla arrays in C and are infact identical to dcarrays except the datatype here being float. In addition however, they support automatic memory allocation when the size of the array increases.
 
 ### Important Functions
 
 - `void dcfexpand(dcfarr *arr)` : automatic memory expansion on overflow.
 - `void dcfappend(dcfarr *arr, int value)` : add an element to the end of the dcarray.
 - `void dcfset(dcfarr *arr, int index, float value)` : set a particular value at the given index
 - `float dcfget(dcfarr *arr, int index)` : get the value at the index
 - `dcarr dcfcopy(dcfarr *arr)` : create a copy of the dcarray
 - `void dcfsort(dcfarr *arr, char *order)` : sort the dcarray in  ascending or descending order. DaiCy uses quick sort for all sorting functions given its favourable time complexity.
 - `dcfarr todcfarr(float arr[], int size)` : convert vanilla C array of floating type to dcfarray so as to make use of all advantages of dcfarray.
 
  
  #### To add
 - `dcfarr dcresizefarr(dcfarr *arr)`
 - `dcfarr dcfswap(float, float)`
 
 *Note: C is not an OOP language and hence doesnot support polymorphism which means functions like sort, append, expand etc which are essentially the same need to be defined with separate names for separate datatypes and that is what has been done or DaiCy as well.*
 
 
 ## 3. DaiCy String (dcstr)
 
 C does not have a "String" datatype unlike many of the modern programming languages, dcstring introduces the the string datatype. It supports most string operations supported by languages such as python and java.
 
 ### Important Functions
 
 - `dcstr dcstrcopy(dcstr *str)` : create a copy of the string
 - `char dccharAt(dcstr *str, int index)` : get character at the specified index value)
 - `dcstr dcstrconcat(dcstr *str1, dcstr *str2)` : concatenate two strings and return the new string
 - `int dcnum_words(dcstr *str)` : number of words in the string.
 - `void dccapitalize(dcstr *str)` : capitalize the first letter of each word in the string.
 - `void dctoupper(dcstr *str)` : convert entire string to lowercase
 - `void dctolower(dcstr *str)` : convert entire string to uppercase
 - `int dcislower(dcstr *str)` : returns 1 if all characters in the string are lowercase and returns 0 otherwise
 - `int dcisupper(dcstr *str)` : returns 1 if all characters in the string are uppercase and returns 0 otherwise
 - `int dcstrcmp(dcstr *str1, dcstr *str2)` : compares the two strings and returns 1, 0 or -1 accordingly
 
 #### To add
 - `dcstr todcstr(char s[])`
 - `dcstr dcsubstr(dcstr *str, int start, int end)`
 
  ## 4. DaiCy Matrix (dcmat)
 
 dcmat is the matrix datatype that daiCy provides. It introduces the ability to add, subtract, mulitply matrices, find transose of a matrix and more. 
 
 *Note: This data type also introduces the new feautre of converting a normal C datatype to a DaiCy datatype. This feature will soon be added for all daiCy datatypes allowing the user to switch over to the daiCy datatypes at any point.*
 
 ### Important Functions
 - `dcmat dcmatadd(dcmat *mat1, dcmat *mat2)` : add two matrices and return the resultant
 - `dcmat dcmatsub(dcmat *mat1, dcmat *mat2)` : subtract two matrices and return the resultant
 - `dcmat dcmatmul(dcmat *mat1, dcmat *mat2)` : multiply two matrices
 - `dcmat dcmatones(int r, int c)` : intialize a matrix of ones
 - `dcmat dcmatzeros(int r, int c)` : initialize a matrix of zeros
 - `dcmat dcmatcopy(dcmat *mat)` : create a copy of the matrix
 - `int dcmattrace(dcmat *mat)` : find the trace of the matrix
 - `void dcmatshow(dcmat *mat)` : display the matrix
 - `dcmat todcmat(int **a, int r, int c)` : convert C datatype to DaiCy datatype
 -  `dcmat dcmattranspose(dcmat *mat)` : find transpose of a matrix
 
  *note: In case of dimensional ambiguity among the two matrices, DaiCyError is raised. The detailed definitions can viewed in the source code for [dcmatrix](https://github.com/kumudlakara/daiCy/blob/main/src/dcmatrix.c).* 
 
 ## 5. DaiCy Stack (dcstack)
 
dcstack introduces the the stack datatype. All stack operations like push, pop etc can be done on dcstacks. dcstack variables also have a "top" property which can be used to obtain the current position of the top pointer and hence access the top of the stack.
 
 ### Important Functions
 - `void dcpush(dcstack* arr, int value)` : push an element to the top of the stack
 - `int dcpop(dcstack *arr)` : pop the element from the top of the stack
 - `void dcshow_stack(dcstack *arr)` : display the contents of the stack


## 6. DaiCy Queue (dcqueue)
 
dcqueue introduces the the queue datatype. It can be manipulated and handled like any normal queue. The dcqueue variables also have front and rear properties which can be used to access the front and rear of the queue respectively. dcqueue works like any other normal queue where elements are added to the rear and removed from the front. In addition to this for efficient use of memory space dcqueues are actually implemented as circular queues under the hood.
 
 ### Important Functions
 - `void dcenq(dcqueue *arr, int value)` : add an element to the end of the queue
 - `int dcdeq(dcqueue *arr)` : remove element from the front of the queue
 - `void dcshow_queue(dcqueue *arr)` : display the contents of the queue
 
 ##### *note: This description/documentation is under process and is not complete as of now. The complete details for all functions can be found as comments in the function definitions in the respecitve files under the [src](https://github.com/kumudlakara/daiCy/tree/main/src) directory.* 
 
 
