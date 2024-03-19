#ifndef _Queue_h_
#define _Queue_h_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
// queue is 0 which means we are not using it
#define Circular_Queue 0
#define COURSES_NUMBER 5
#define NAME_LENGTH 20
// a struct is defined with the data of the student
typedef struct
{
    int roll;
    char F_Name[NAME_LENGTH];
    char L_Name[NAME_LENGTH];
    float GPA_Score;
    int courses_id[COURSES_NUMBER];
} student_t;

// define queue data structure
typedef struct
{
    unsigned int length;
    unsigned int count;
    student_t *head;
    student_t *base;
    student_t *tail;
} Queue_t;
// status that is returned from the each functions
typedef enum
{
    Queue_no_error,
    Queue_Null,
    Queue_full,
    Queue_not_full,
    Queue_empty,
    Queue_not_empty
} Queue_status;
// function declarations

// queue intialization
Queue_status create_queue(Queue_t *q, student_t *queue, unsigned int length);
// adding new item into the queue
Queue_status Enqueue(Queue_t *q, student_t queue);
// removing an item from the queue
Queue_status Dequeue(Queue_t *q, student_t *queue);
// checking if the queue is empty or not
Queue_status is_Empty(Queue_t *q);
// check if the queue is full or not
Queue_status is_Full(Queue_t *q);
// print the content of a queue
void printQueue(Queue_t *q);

#endif