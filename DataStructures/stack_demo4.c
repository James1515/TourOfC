//=====================================================
//Author: James Anthony Ortiz
//File:   stack_demo4.c
//Description: An implementation of a Stack DS, with
//a dynamically allocated linked-list of array blocks.
//All operations are performed in constant-time O(1)
//Only exception is the remove_stack function in O(n) time.
//Compile: cc -Wall -Wextra stack_demo4.c -o stack_demo4
//======================================================


#include <stdio.h>
#include <stdlib.h>

typedef struct st_t{
  int *base;
  int *top;
  int size;
  struct st_t *previous;
}stack_t;

//Function create_stack:
//Returns a pointer, and creates
//a stack DS to the size needed.
stack_t *create_stack(int size){
  stack_t *st;
  st = (stack_t *) malloc(sizeof(stack_t));
  st->base = (int *)malloc (size *sizeof(int));
  st->size = size;
  st->top = st->base;
  st->previous = NULL;
  return (st);
}//end function create_stack()

//Function stack_empty()
//Checks to see if the stack is empty
int stack_empty(stack_t *st){
  return(st->base == st->top && st->previous == NULL);
}//end function stack_empty()


//Function push()
//Recieves an int value, and the stack pointer.
//Pushes a new value to the stack, if there is
//not enough space a new stack is created.
//And new space will be added accordingly.
void push(int x, stack_t *st){
  if(st->top < st->base + st->size){
    *(st->top) = x;
    st->top += 1;
  }
  else{
    stack_t *new;
    new = (stack_t *) malloc(sizeof(stack_t));
    new->base = st->base;
    new->top = st->top;
    new->size = st->size;
    new->previous = st->previous;
    st->previous = new;
    st->base = (int *) malloc(st->size * sizeof(int));
    st->top = st-> base + 1;
    *(st->base) = x;
  }
}//end function push()


int pop(stack_t *st){
  if(st->top == st->base){
    stack_t *old;
    old = st->previous;
    st->previous = old->previous;
    free(st->base);
    st->base = old->base;
    st->top = old->top;
    st->size = old->size;
    free(old);
  }
  st->top -= 1;
  return(*(st->top));
}//end function pop()

//Function top_element()
//Finds the top_element of the stack
int top_element(stack_t *st){
  if(st->top == st->base){
    return( *(st->previous->top -1));
  }
  else{
    return ( *(st->top -1));
  }
}//end function top_element()


//Function remove_stack()
//Removes allocated memory from the stack
void remove_stack(stack_t *st){
  stack_t *tmp;
  do{
    //Create temp stack to free currently used one.
    tmp = st->previous;
    free(st->base);
    free(st);
    st = tmp;
  }while(st != NULL);
}// end function remove_stack()

//====================================================
//Main driver program for Stack LIFO Data-Structure:
//Push(), Pop(),and Peek() (top-element) are all
//constant time O(1) performance moves.
//Only removing memory from the stack is an
//exception here, as it has to be done in
//linear-time O(n) because memory has to be discloated
//from each node in the linked-list.
//====================================================
int main(void){
  
  //Create a stack with 10 items:
  stack_t *stack = create_stack(10);

  printf("Pushing elements 0-9 onto the stack:\n");

  //Stmts. used to check is stk is empty:
  if(stack_empty(stack) == 0){
    printf("Stack is currently empty.\n");
  }else{
    printf("Stack is not empty.\n");
  }
  
  for(int i = 0; i < 10; i++){
    printf("Pushing %d to the stack...\n", i);
    push(i, stack); //push numbers 0-9 onto stk
  }

  printf("Now popping two elements from the stack...\n");

  //Popping two elements from the top of the stack.
  printf("Popping element %d from the top\n", pop(stack));
  printf("Popping element %d from the top\n", pop(stack));

  //Show the item at the top of the stk:
  printf("Now the item at the top of the stack is: %d\n", top_element(stack));

  //Pushed number 550 to the stack
  push(550, stack);
  printf("Pushed 550 to the top of the stack: \n");
  printf("Now the top-element of the stack is: %d\n", top_element(stack));
  printf("Freeing up dynamically-allocated memory from the heap (used by stack)\n");

  //Freeing memory from heap (dynamically-allocated memory):
  remove_stack(stack);  
  return 0;
}//end MAIN
