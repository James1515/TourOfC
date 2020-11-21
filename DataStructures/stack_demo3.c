//=================================================================
//Author: James Anthony Ortiz
//File: stack_demo3.c
//Description: Stack implemented as a dynamically linked-list in
//C99
//Compile: cc stack_demo3.c -o stack_demo3
//=================================================================


#include <stdio.h>
#include <stdlib.h>

typedef struct st_t { int item;
struct st_t *next; } stack_t;

stack_t *create_stack(void)
{ 
  stack_t *st;
  st = get_node(); //TODO: To be implemented and added to example.
  st->next = NULL;
  return(st);
}

int stack_empty(stack_t *st)
{ 
 return( st->next == NULL );
}

void push( item_t x, stack_t *st)
{ 
  stack_t *tmp;
  tmp = get_node();
  tmp->item = x;
  tmp->next = st->next;
  st->next = tmp;
}


int pop(stack_t *st)
{
  stack_t *tmp; int tmp_item;
  tmp = st->next;
  st->next = tmp->next;
  tmp_item = tmp->item;
  return_node(tmp); //TODO: return_node to be implemented at a later time.
  return( tmp_item );
}//end function pop()

item_t top_element(stack_t *st)
{
  return( st->next->item );
} //end function top_element()


void remove_stack(stack_t *st)
{
  stack_t *tmp;
  do
  { 
    tmp = st->next;
    return_node(st);
    st = tmp;
  }
  while (tmp != NULL);
}//end fucntion remove_stack()


//Driver class for linked-list version of Stack:
int main(void)
{
  
  return 0;
}
