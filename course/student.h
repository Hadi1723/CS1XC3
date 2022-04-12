/**
 * @file student.h
 * @author Abdul-Hadi Siddiqui (sidda1@mcmaster.ca)
 * @brief Student library for managing students, including Student type definition 
 *        and Student type function declarations.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Student type stores a student with fields first_name, last_name, id, grade, num_grades
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /**< the student's first name */
  char last_name[50]; /**< the student's last name  */
  char id[11]; /**< the student's id  */
  double *grades; /**< the list of grades for the student */
  int num_grades; /**< the number of grades for student*/
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
