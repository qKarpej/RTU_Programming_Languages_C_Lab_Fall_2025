/*
 * week4_1_dynamic_array.c
 * Author: [Aleksejs Pjavka]
 * Student ID: [241ADC005]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int *arr = NULL;
  int sum = 0;
  double average;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
    sum += arr[i];
  }

  average = sum / n;

  printf("Sum = %d\n", sum);
  printf("Average = %.2f\n", average);

  free(arr);

  return 0;
}
