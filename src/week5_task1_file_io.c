// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100] = "data.txt";
  char line[256];

  // TODO: 1. Open file for writing (mode = "w")
  fp = fopen(filename, "w");
  // TODO: 2. Check if file opened successfully
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  // TODO: 3. Write 2–3 lines of text to the file using fprintf()
  fprintf(fp, "%s\n", "What a beautiful day!");
  fprintf(fp, "%s\n", "It is sunny outside!");
  // TODO: 4. Close the file
  fclose(fp);
  // TODO: 5. Open file again for reading (mode = "r")
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error oppening file!\n");
    return 1;
  }
  // TODO: 6. Use fgets() in a loop to read and print each line to the console
  int lineCount = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    lineCount++;
    printf("Read the line %d: %s", lineCount, line);
  }
  // TODO: 7. Close the file
  fclose(fp);
  // BONUS: ask user for filename instead of using default "data.txt"
  // BONUS: count number of lines read
  printf("\nTotal lines read: %d\n", lineCount);

  return 0;
}
