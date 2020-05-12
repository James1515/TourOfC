/*
Author: James Anthony Ortiz
File: addfrac.c
Date: 05/11/2020 
File: addfrac.c
Description: Adds two fractions

Compile: gcc -std=c99 -Wall addfrac.c -o addfrac
*/

#include <stdio.h>

int main()
{
  int num1, num2;
  int denom1, denom2;
  int result_num;
  int result_denom;


  printf("Enter first fraction: ");
  scanf("%d/%d", &num1, &denom1);

  printf("Enter second fraction: ");
  scanf("%d/%d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;

  result_denom = denom1 * denom2;

  printf("The sum is %d/%d\n", result_num, result_denom);

  return 0;
}
