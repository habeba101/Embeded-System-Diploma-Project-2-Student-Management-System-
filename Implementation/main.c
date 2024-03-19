#include "App.h"

int main()
{
    // intialize the queue
    student_t studentss[50];
    printf("Welcome to the Student Management System\n");
    if (create_queue(&Queue_List, studentss, 50) == Queue_no_error)
    {
        while (1)
        {
            choice();
        }
    }

    return 0;
}
