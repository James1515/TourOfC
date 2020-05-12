/*
Author: James Anthony Ortiz
File: exp.c
Date: 05/11/2020
Description: Write a program that asks the user for 
the value of x for the given polynomial:
3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6

Compile: gcc -std=c99 -Wall exp.c -o exp
 */


#include <stdio.h>

int main()
{
  int x;
  long int pol = 0;


  printf("Please enter a value for x: ");
  scanf("%d", &x);

  pol = 3*(x*x*x*x*x) + 2*(x*x*x*x) - 5*(x*x*x) - (x*x) + 7*(x) - 6;

  printf("The value of the polynomial is: %ld \n", pol);
  return 0;
}
