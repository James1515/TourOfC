//=======================================================================
//Author: James Anthony Ortiz
//File: stack_demo1.c
//Description: An example of an implementation of a stack in C99
//Compile: cc stack_demo1.c -o stack_demo1
//======================================================================

#include <stdio.h>
#define MAXSIZE 10

int i = 0;
int stack[MAXSIZE];

_Bool stack_empty(void)
{
  return(i == 0);
}

int push(int x)
{
  if(i < MAXSIZE)
  {
    stack[i++] = x;
    return 0;
  }
  else
    return -1;
}

int pop(void)
{
  return(stack[--i]);
}

int main(void)
{

  for(int i = 0; i < MAXSIZE; i++)
  {
    printf("Pushing %d into the stack \n", i);
    push(i);
  }
  
  //A demo of popping values from a stack:
  printf("Popped 1st value, the value is: %d \n", pop());
  printf("Popped 2nd value, the value is: %d \n", pop());
  printf("Popped 3rd value, the value is: %d \n", pop());

  //Boolean check to see if the stack is empty:
  printf("Is the stack empty? %d \n", stack_empty());


  return 0;
}

