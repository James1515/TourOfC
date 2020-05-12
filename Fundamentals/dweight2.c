//
//Author: James Anthony Ortiz
//File: dweight.c
//Description: Computes the dimensional weight of the box through user input.
//Compile: gcc -std=c99 -Wall dweight2.c -o dweight
//

#include <stdio.h>

int main(void)
{
  int height, length, width, volume, weight;

  printf("Enter height of box: ");
  scanf("%d", &height);

  printf("Enter length of box: ");
  scanf("%d", &length);

  printf("Enter width of box: ");
  scanf("%d", &width);

  volume = height * length * width;
  weight = (volume + 165) / 166;

  printf("Volume (in cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", weight);

  return 0;
}//end MAIN
