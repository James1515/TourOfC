//====================================================================
//Author: James Anthony Ortiz
//File: stack_demo2.c
//Description: A second implementation of a Stack data structure in
//C99, with dynamis allocation via struct.
//Compile: cc stack_demo2.c -0 stack_demo2
//====================================================================

#include <stdio.h>
#include <stdlib.h>


typedef struct 
{ 
	int *base;
	int *top;
	int size;
} stack_t;

stack_t *create_stack (int size)
{
 stack_t *st;
 st = (stack_t *) malloc(sizeof(stack_t));
 st->base = (int *) malloc(size * sizeof(int));
 st->size = size;
 st->top = st->base;
 return (st);
}//create_stack()


int stack_empty(stack_t *st)
{
 return (st->base == st->top);
}//end function stack_empty()

int push(int x, stack_t *st)
{
 if(st->top < st->base + st->size)
 {
  *(st->top) = x; 
   st->top += 1;
   return (0);
 }
 else{
  return -1;
 }

}//end function push()


int pop(stack_t *st)
{
  st->top -= 1;
  return (*(st->top -1));
}//end function pop


int top_element(stack_t *st)
{
 return ( *(st->top -1)); 
}//end function top_element()

void remove_stack(stack_t *st)
{
  free(st->base);
  free(st);
}//end function remove_stack()



//Driver program for Stack implementation:
int main (void)
{

 //Creates a stack to hold 10 int values:
printf("Creating a stack with 10 items...\n");
 stack_t *st =  create_stack(10);

 //Check to see if the stack is currently empty:
 if(stack_empty(st) == 0)
   printf("Stack is not empty.\n");
 else 
   printf("Stack is empty.\n");


 //Pushing int values into the stack:
 push(3, st);
 printf("Pushing 3 into the stack.\n");
 push(5, st);
 printf("Pushing 5 into the stack.\n");
 push(7, st);
 printf("Pushing 7 into the stack.\n");
 push(9, st);
 printf("Pushing 9 into the stack.\n");
 push(11, st);
 printf("Pushing 11 into the stack.\n");
 push(13, st);
 printf("Pushing 13 into the stack.\n");


 printf("\n Now the stack looks like this: [3, 5, 7, 9, 11, 13]\n");

 //Find the top element of the stack:
 printf("The top element of the stack is currently: %d\n", top_element(st));

 //Popping two items from the stack:
 printf("Popping two items from the stack... \n");

 pop(st);
 pop(st);

 printf("The top element is now: %d\n", top_element(st));

 
 //Freeing memory from stack:
 remove_stack(st);

 return 0;
}
