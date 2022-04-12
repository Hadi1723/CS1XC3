/**
 * @file student.c
 * @author Abdul-Hadi Siddiqui (sidda1@mcmaster.ca)
 * @brief Student library for managing students, including definitions of Student type 
 *        function.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Increments the number of courses for student and stores grade for new course
 * 
 * @param student a single student represented as a pointer
 * @param grade the grade for the new course for student
 * @return nothing
 */

void add_grade(Student* student, double grade)
{
  student->num_grades++;

  //initializes list of grades if record of grades did not existed
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    
    //increments size of dynamic array if record of grades already existed
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Computes average for single student
 * 
 * @param student a single student represented as a pointer
 * @return double 
 */
double average(Student* student)
{
  // a student with no courses cannot have an average
  if (student->num_grades == 0) return 0;

  double total = 0;

  //adds all individual grades of studnets to compute average
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];

  return total / ((double) student->num_grades);
}

/**
 * @brief Prints name, id, grades, and the average for a single student
 * 
 * @param student a single student represented as a pointer
 * @return nothing
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");

  //displays all grades of student rounded to 2 decimal place
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);

  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Generates information for new student
 * 
 * @param grades number of grades new student will possess
 * @return Student* 
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  //allocates dynamic memory to store informtaion of new student
  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  // randomly generates the id for new student
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  //generates the grades of new student
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}