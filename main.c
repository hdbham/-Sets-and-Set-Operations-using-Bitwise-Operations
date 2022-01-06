
#include <stdio.h>
#include <ctype.h>

int getSetSize(char whichSet);
int setCreation(int size);
void printSet(int mySet, int integerOut, char setName);

int main (void) {

  printf("CS 2130 - Computational Structures - Hunter Burningham\nThis program reads in the values of two sets and displays\nthe results of several operations on the sets.\n\n");

  int setA = 0; 
  int setB = 0;
	int i; // used as a loop control variable
	int value; // the value read in from the user
	int num; // the number of elements in the set

	num = getSetSize('A');
	setA = setCreation(num);
	num = getSetSize('B');
	setB = setCreation(num);
  printf("\nInput Sets");
  printSet(setA, 1,'A');
	printSet(setB, 1,'B');

  //returns the complement of two sets
  printf("\n\nThe Complement of A = ");
  printSet(~setA, 0,'X');

  //returns the union of two sets 
  printf("\nThe Union of A and B = ");
  printSet(setA|setB, 0,'X');

  //returns the intersection of two sets
  printf("\nThe Intersection of A and B = ");
  printSet(setA&setB, 0,'X');

  //returns the difference of two sets
  printf("\nThe Difference of A and B = ");
  printSet(setA&~setB, 0,'X');

  //returns the symetric difference of two sets
  printf("\nThe Symetric Difference of A and B= ");
  printSet(setA^setB, 0,'X');

	printf("\n\n----------------------------------\n\nBye!\n\n");
	return 0;
}

//determines set size, num passes to setCreation as size to determine forloop length in setCreation
int getSetSize(char whichSet){
LOOP: for (int num = 0; num < 1; ++num){
  int num;
	printf("\nPlease enter the number of elements in the set [set%c]: ", whichSet);
	if (scanf("%d", &num) == 1) {
    if(num > 9 || num < 0) {
      printf("\nValue out of range.\n\n");
      num = 0;
      goto LOOP; 
      }
  return num;
  }
  else
   {
     printf("Not a valid input\n\n");
      exit(1); //protects memory
      }
}}

//sets value to positional value using shift bitwise operator
int setCreation(int size) {
  int theSet = 0;
	for (int i=0; i< size; ++i) {
    int value;
		printf("Please enter number [0-9] %i: ", i+1);
		scanf("%i", &value);
    if(value >=10 || value < 0) {
      printf("\nValue out of range.\n\n");
      i = i - 1;
      }
    else
		theSet = theSet | (1 << value);
	}
return theSet;
} 

//returns set values by using & bitwise operator to determine place of setbits in 16 bit int

void printSet(int mySet, int integerOut, char setName ){
  if(integerOut != 0){
    //	printf("\nThe resulting integer for the set [Set%c] is: %i",setName, mySet);*/ //
    printf("\nSet %c = ",setName);
  }
	printf("{"); 
  int value = 0;
  int i;
	for(i=0; i<=10; i++) {
		if((mySet & (1 << i)) > 0) {
    if(value) printf(",");
			printf("%i", i);
      value = 1;
		}
  }
  printf("}");
}
