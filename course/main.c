/**
 * @mainpage Course And Student Functions Demonstration
 *  
 * The course and student functions demonstration shows how multiple functions in the course 
 * and student library work, including:
 * - enrolling new students to a course
 * - printing informtaion for a course
 * - identifying the top student in a course
 * - printing the name of all passing students for a course
 * - adding new grade for a student
 * - computing the average for a student
 * - printing informtaion of a course
 * - generating new student
 * 
 * @file main.c
 * @author Abdul-Hadi Siddiqui (sidda1@mcmaster.ca)
 * @brief Runs demonstration code for course and student library methods
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

int main()
{
  srand((unsigned) time(NULL));

  //allocates dynamic memory to store information regarding MATH101
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  //enrolles 20 new students with 8 initial grades to MATH101
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");

  //prints the name of all passing students for MATH101
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}