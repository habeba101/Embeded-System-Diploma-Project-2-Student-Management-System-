#ifndef _APP_H_
#define _APP_H_

#include "Queue.h"
// Queue created
Queue_t Queue_List;
// pointer of type student
student_t students ;
// for counting
int i;
// a variable to store status values
Queue_status status;
// a user choose an option from a list of choices to use the system
void choice();
// adding a list of students from a file
void add_student_file();
// user adds students by hand
void add_student_manually();
// search the list to find a student by his roll number
void find_by_roll_number();
// search the list to find a student by his first name
void find_by_first_name();
// search the list to find a student by his last name
void find_by_last_name();
// search the list to find students inrolled in certain courses
void find_students_by_courses();
// get the total number of students entered in the system
void total_of_students();
// delete a certain student by his roll number
void delete_student();
// update the data of a student
void update_student();
// show all students
void show_all_students();
// exit from the system
void Exit_Fun();
// check Roll Number
int Roll_Check(int roll);
#endif