// week5_task4_struct_binary_io.c
// OPTIONAL Bonus Task 4: Binary File Version (Advanced)
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define BINARY_FILE "student.bin"

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student_binary(Student s, const char *filename);
Student load_student_binary(const char *filename);
long get_file_size(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    printf("Saving student in binary format...\n");
    save_student_binary(s1, BINARY_FILE);

    printf("Loading student from binary file...\n");
    Student s2 = load_student_binary(BINARY_FILE);

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    long size = get_file_size(BINARY_FILE);
    if (size >= 0)
        printf("Binary file size: %ld bytes\n", size);

    return 0;
}

// Save struct directly in binary format
void save_student_binary(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    size_t written = fwrite(&s, sizeof(Student), 1, fp);
    if (written != 1) {
        printf("Error writing student data!\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    printf("Student saved successfully to '%s'.\n", filename);
}

// Load struct from binary file
Student load_student_binary(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    size_t read = fread(&s, sizeof(Student), 1, fp);
    if (read != 1) {
        printf("Error reading student data!\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return s;
}

// Helper to check binary file size
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file to get size!\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}
