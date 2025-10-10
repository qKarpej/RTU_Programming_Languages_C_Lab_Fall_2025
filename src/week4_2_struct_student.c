/*
 * week4_2_struct_student.c
 * Author: [Aleksejs Pjavka]
 * Student ID: [241ADC005]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and
 * grade. Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student s1;
  struct Student s2;

  strcpy(s1.name, "Aleksejs Pjavka");
  s1.id = 101;
  s1.grade = 9.68;

  strcpy(s2.name, "Ivans Pupkins");
  s2.id = 102;
  s2.grade = 7.53;

  printf("Student 1:\n");
  printf("  Name:  %s\n", s1.name);
  printf("  ID:    %d\n", s1.id);
  printf("  Grade: %.2f\n", s1.grade);

  printf("\nStudent 2:\n");
  printf("  Name:  %s\n", s2.name);
  printf("  ID:    %d\n", s2.id);
  printf("  Grade: %.2f\n", s2.grade);

  return 0;
}
