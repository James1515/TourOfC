/*
Author: James Anthony Ortiz
File: telformat.c
Date: 05/11/2020
Description: Create a program that prompts the user to enter 
a telephone number in the form (xxx) xxx-xxxx and displays 
it in the form xxx.xxx.xxxx.

Compile: gcc -std=c99 -Wall telformat.c -o telformat
 */

#include <stdio.h>

int main()
{
  //Variable declarations
  int first_three_dig;
  int sec_three_dig;
  int last_dig;

  //Prompt user for input:
  printf("Enter phone number [(xxx) xxx-xxxx]: \n");
  scanf("(%d) %d-%d", &first_three_dig, &sec_three_dig, &last_dig);

  //Display Result:
  printf("You entered: %d.%d.%d\n", first_three_dig, sec_three_dig, last_dig);
  return 0;
}


