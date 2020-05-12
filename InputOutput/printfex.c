/*
Author: James Anthony Ortiz
File: printfex.c
Description: An exmaple of the different conversion 
specifications of the format string function, printf.

Compile: gcc -std=c99 -Wall printfex.c -o printfex
*/

#include <stdio.h>

int main()
{
  int i, j;
  float x, y;

  i = 10;
  j = 20;
  x = 43.2892f;
  y = 5527.0f;


  printf("i = %d, j = %d, x = %f, y = %f \n", i, j, x, y);

  return 0;
}
