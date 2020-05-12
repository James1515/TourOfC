/*
Author: James Anthony Ortiz
File: tax.c
Date: 5/11/2020
Description: Calculates tax given dollars and cents.
Compile: gcc -std=c99 -Wall tax.c -o tax
 */


#include<stdio.h>

int main()
{
  int dollars;
  int cents;

  printf("Please enter the amount of dollars: ");
  scanf("%d", &dollars);

  printf("Please enter the amount of cents: ");
  scanf("%d", &cents);


  printf("The total amount is the following: $%d.%d \n", dollars, cents);
  return 0;
}
