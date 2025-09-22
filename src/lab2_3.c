#include <math.h>
#include <stdio.h>

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;

  //Program is not working with sqrt(n) despite including <math.h>
  for (int i = 3; i <= n/2; i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int n;

  printf("Enter an integer n (>= 2): ");
  scanf("%d", &n);

  if (n < 2) {
    printf("Error! Number %d is not valid.", n);
    return 0;
  } else {
    printf("Prime number up to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
      if (is_prime(i)) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }
  return 0;
}
