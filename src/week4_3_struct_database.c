/*
 * week4_3_struct_database.c
 * Author: [Aleksejs Pjavka]
 * Student ID: [241ADC005]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("\nEnter data for student %d:\n", i + 1);

    printf("  Name: ");
    getchar();
    fgets(students[i].name, sizeof(students[i].name), stdin);

    students[i].name[strcspn(students[i].name, "\n")] = '\0';

    printf("  ID: ");
    scanf("%d", &students[i].id);

    printf("  Grade: ");
    scanf("%f", &students[i].grade);
  }

  printf("\n=== Student Records ===\n");
  for (int i = 0; i < n; i++) {
    printf("Student %d:\n", i + 1);
    printf("  Name:  %s\n", students[i].name);
    printf("  ID:    %d\n", students[i].id);
    printf("  Grade: %.2f\n", students[i].grade);
  }

  float total = 0;
  for (int i = 0; i < n; i++) {
    total += students[i].grade;
  }
  printf("\nAverage grade: %.2f\n", total / n);

  free(students);

  return 0;
}
