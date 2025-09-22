#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
  int res = 1;
  if (n == 0) {
    return 1;
  } else {
    for (int i = 1; i <= n; i++) {
      res *= i;
    }
  }
  return res;  // placeholder
}

int main(void) {
  int n;

  printf("Enter a non-negative number n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error! Integer %d is not a positive integer.", n);
  } else {
    long long result = factorial(n);
    printf("%lld", result);
  }
  return 0;
}
