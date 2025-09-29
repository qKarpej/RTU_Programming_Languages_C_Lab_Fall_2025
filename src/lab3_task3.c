/*
 * Lab 3, Task 3
 * Aleksejs Pjavka, 241ADC005
 *
 * Implement basic string handling functions.
 * Write your own versions of:
 *   - my_strlen (finds string length)
 *   - my_strcpy (copies string from src to dest)
 *
 * Rules:
 *   - Do not use <string.h> functions for strlen/strcpy.
 *   - Use loops and manual pointer/array access.
 *
 * Example:
 *   char s[] = "hello";
 *   int len = my_strlen(s);   // should return 5
 *
 *   char buffer[100];
 *   my_strcpy(buffer, s);     // buffer now contains "hello"
 */

#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
  // TODO: Test your functions here
  char test[] = "Programming in C";
  char copy[100];

  int len = my_strlen(test);
  printf("Length: %d\n", len);

  my_strcpy(copy, test);
  printf("Copy: %s\n", copy);

  return 0;
}

// Implement functions below
int my_strlen(const char *str) {
  int str_len = 0;
  while (*str++) {
    str_len++;
  }
  return str_len;  // placeholder
}

void my_strcpy(char *dest, const char *src) {
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}
