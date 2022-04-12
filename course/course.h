/**
 * @file course.h
 * @author Abdul-Hadi Siddiqui (sidda1@mcmaster.ca)
 * @brief Course library for managing courses, including Course type definition 
 *        and Course type function declarations.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "student.h"
#include <stdbool.h>

/**
 * @brief Course type stores a course with fields name, code, students, total_students
 * 
 */
typedef struct _course 
{
  char name[100]; /**< the course name */
  char code[10]; /**< the course code */
  Student *students; /**< the students enrolled in course */
  int total_students; /**< the total number of students in course */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


