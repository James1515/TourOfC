//
//Author: James Anthony Ortiz
//File: dweight.c
//Description: Calculate the weight of a shipping box 12" x 10" x 8"
//Compile: gcc -std=c99 -Wall dweight.c -o dweight
//

#include <stdio.h>

int main(void)
{
  int height, length, width, volume, weight;

  height = 8;
  length = 12;
  width = 10;
  volume = height * length * width;
  weight = (volume + 165) / 166;

  printf("Dimenstions: %dx%dx%dx\n", length, width, height);
  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", weight);


  return 0;
}
