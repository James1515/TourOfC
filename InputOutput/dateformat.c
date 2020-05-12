/*
Author: James Anthony Ortiz
File: dateformat.c 
Date: 05/11/2020
Description: Given a dd/mm/yyyy format,
provide the yyyymmdd format for the 
given date from user input.
Compile: gcc -std=c99 -Wall dateformat.c -o dateformat
 */


#include <stdio.h>

int main(void)
{
  int year;
  int month;
  int day;

  printf("Please enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);


  //If the day and the month is less than ten or greater than
  //and equal to zero:

  if((day < 10 && month < 10) && (day >= 0 && month >= 0))
  {
    printf("You entered the date: %d0%d0%d \n", year, month, day);
    return 0;
  }



  //If the day is less than two digits append 0
  //else - if the month is less than two digits, append a zero.
  if(day < 10 && day >= 0)
  {
    printf("You entered the date: %d%d0%d \n", year, month, day);
    return 0;
  }
  else if (month < 10 && month >= 0)
  {
    printf("You entered the date: %d0%d%d \n", year, month, day);
    return 0;
  }


  printf("You entered the date: %d%d%d \n", year, month, day);
  return 0;
}

