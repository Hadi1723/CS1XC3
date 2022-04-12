/**
 * @file course.c
 * @author Abdul-Hadi Siddiqui (sidda1@mcmaster.ca)
 * @brief Course library for managing courses, including definitions of Course type 
 *        function.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Increments the number of students in course and stores record of new student 
 * 
 * @param course a course represented as a pointer
 * @param student a student represented as a pointer
 * @return nothing
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;

  
  if (course->total_students == 1) 
  {
    //initializes list of students if record of students did not existed
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    //increments size of dynamic array if record of students already existed
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints name, code, number of students, and list of students for a single course
 * 
 * @param course a course represented as a pointer 
 * @return nothing
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");

  //printing names of all students enrolled in the course
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Identifies the top student in the course
 * 
 * @param course a course represented as a pointer
 * @return Student* 
 */
Student* top_student(Course* course)
{
  //a course with no students cannot have a top student
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
  
  //prints average for each student enrolled in course
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    
    //storing the record of student who has highest average
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * @brief Computes dynamic array of passing students for the given course
 * 
 * @param course a course represented as a pointer
 * @param total_passing the number of passing students is represented as a pointer
 * @return Student* 
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  //counts the number of passing students if a student average is 50% or above
  for (int i = 0; i < course->total_students; i++)
    if (average(&course->students[i]) >= 50) count++;
  
  //initializing array storing list of passing students
  passing = calloc(count, sizeof(Student));

  int j = 0;

  //adds the record of a student to the list if their average is 50% or above
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}