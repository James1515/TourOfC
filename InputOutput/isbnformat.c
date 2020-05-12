/*
Author: James Anthony Ortiz
File: isbnformat.c
Date: 05/11/2020
Description: Given an ISBN number, attempt to parse information
from the 13 digit code into segments.

Compile: gcc -std=c99 -Wall isbnformat.c -o isbnformat
 */

//IO Library:
#include <stdio.h>

int main(void)
{

  //Variable declarations:
  int g_s_prefix_;
  int group_identifier_;
  int publisher_code_;
  int item_number_;
  int check_digit_;


  //Create prompt for user input:
  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &g_s_prefix_, &group_identifier_, &publisher_code_, &item_number_, &check_digit_);

  //Display results:
  printf("GS1 Prefix: %d\nGroup identifier: %d\nPublisher Code: %d\nItem number: %d\nCheck digit: %d\n", g_s_prefix_, group_identifier_,
         publisher_code_, item_number_, check_digit_);

  return 0;
}
