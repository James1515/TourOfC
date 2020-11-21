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

stack_t *create_stack(int size){
  stack_t *st;
  st = (stack_t *) malloc(sizeof(stack_t));
  st->base = (int *)malloc (size *sizeof(int));
  st->size = size;
  st->top = st->base;
  st->previous = NULL;
  return (st);
}//end function create_stack()

int stack_empty(stack_t *st){
  return(st->base == st->top && st->previous == NULL);
}//end function stack_empty()

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
}

int top_element(stack_t *st){
  if(st->top == st->base){
    return( *(st->previous->top -1));
  }
  else{
    return ( *(st->top -1));
  }
}//end function top_element()

void remove_stack(stack_t *st){
  stack_t *tmp;
  do{
    tmp = st->previous;
    free(st->base);
    free(st);
    st = tmp;
  }while(st != NULL);
}// end function remove_stack()

int main(void)
{
  
  return 0;
}
