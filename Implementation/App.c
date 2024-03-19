#include "App.h"

// a user choose an option from a list of choices to use the system
void choice()
{
    int ch;
    printf("---------------------------------------- \n");
    printf("Choose the Task that you want to perform \n");
    printf("1. Add the Student details from Text File \n");
    printf("2. Add the Student Details manually \n");
    printf("3. Find the Student Details by Roll Number \n");
    printf("4. Find the Student Details by First Name \n");
    printf("5. Find the Student Details by Last Name \n");
    printf("6. Find the Student Details by Course \n");
    printf("7. Find the Total Number of Students \n");
    printf("8. Delete Students by Roll Number \n");
    printf("9. Update Students by Roll Number \n");
    printf("10. Show All Students \n");
    printf("11. Exit from the System \n");
    printf("Enter your Choice to perform the Task \n");
    scanf("%d", &ch);
    while (getchar() != '\n')
        ;
    printf("---------------------------------------- \n");
    switch (ch)
    {
    case 1:
        add_student_file();
        break;
    case 2:
        add_student_manually();
        break;
    case 3:
        find_by_roll_number();
        break;
    case 4:
        find_by_first_name();
        break;
    case 5:
        find_by_last_name();
        break;
    case 6:
        find_students_by_courses();
        break;
    case 7:
        total_of_students();
        break;
    case 8:
        delete_student();
        break;
    case 9:
        update_student();
        break;
    case 10:
        show_all_students();
        break;
    case 11:
        Exit_Fun();
        break;
    default:
        printf("[ERROR] Wrong Option \n");
        break;
    }
}
// adding a list of students from a file
void add_student_file()
{
    FILE *student_File;
    student_File = fopen("Data.txt", "r");
    if (student_File == NULL)
    {
        printf("[ERROR] Data.txt File is not Found. \n");
        printf("[ERROR] Adding Students from file Failed \n");
        return;
    }
    while (!feof(student_File))
    {
        fscanf(student_File, "%d", &students.roll);
        if (Roll_Check(students.roll) == 1)
        {
            fscanf(student_File, "%s", students.F_Name);
            fscanf(student_File, "%s", students.L_Name);
            fscanf(student_File, "%f", &students.GPA_Score);
            for (i = 0; i < COURSES_NUMBER; i++)
            {
                fscanf(student_File, "%d", &students.courses_id[i]);
            }
            if (Enqueue(&Queue_List, students) == Queue_no_error)
                printf("[INFO] Student Details is added Successfully \n");
            else
            {
                printf("[ERROR] Student details adding Failed by File \n");
                return;
            }
        }
    }
    fclose(student_File);
    total_of_students();
}
// user adds students by hand
void add_student_manually()
{
    printf("Add Student Details \n");
    printf("---------------------------------------- \n");
    printf("\n Enter Student's Roll Number : ");
    scanf("%d", &students.roll);
    if (Roll_Check(students.roll) == 1)
    {
        printf("\n Enter Student First Name : ");
        scanf("%s", &students.F_Name);
        printf("\n Enter Student Last Name : ");
        scanf("%s", &students.L_Name);
        printf("\n Enter Student GPA Score : ");
        scanf("%f", &students.GPA_Score);
        printf("Enter The Course ID of each Course \n");
        for (i = 0; i < COURSES_NUMBER; i++)
        {
            printf("\n Enter Student Course %d:", i + 1);
            scanf("%d", &students.courses_id[i]);
        }
        if (Enqueue(&Queue_List, students) == Queue_no_error)
            printf("[INFO] Student Details is added Successfully \n");
        else
            printf("[ERROR] Student List is Full \n");
        printf("---------------------------------------- \n");
    }
    total_of_students();
}
// search the list to find a student by his roll number
void find_by_roll_number()
{
    int Roll_Num;
    char temp_text[40];
    student_t *temp;
    temp = Queue_List.tail;
    printf("Enter Student Roll Number \n");
    gets(temp_text);
    Roll_Num = atoi(temp_text);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (temp->roll == Roll_Num)
        {
            printf("Student First Name is %s \n", temp->F_Name);
            printf("Student Last Name is %s \n", temp->L_Name);
            printf("Student Roll Number is %d \n", temp->roll);
            printf("Student GPA Score is %f \n", temp->GPA_Score);
            printf("The Course ID is %d \n", temp->courses_id[0]);
            printf("The Course ID is %d \n", temp->courses_id[1]);
            printf("The Course ID is %d \n", temp->courses_id[2]);
            printf("The Course ID is %d \n", temp->courses_id[3]);
            printf("The Course ID is %d \n", temp->courses_id[4]);
            printf("---------------------------------------- \n");
            return;
        }
        else
            temp++;
    }
    printf("[ERROR] Roll Number %d not found \n", Roll_Num);
    printf("---------------------------------------- \n");
}
// search the list to find a student by his first name
void find_by_first_name()
{
    int flag = 0;
    char temp_text[40];
    student_t *temp;
    temp = Queue_List.tail;
    printf("Enter Student First Name \n");
    gets(temp_text);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (strcmp(temp->F_Name, temp_text) == 0)
        {
            flag = 1;
            printf("Student First Name is %s \n", temp->F_Name);
            printf("Student Last Name is %s \n", temp->L_Name);
            printf("Student Roll Number is %d \n", temp->roll);
            printf("Student GPA Score is %f \n", temp->GPA_Score);
            printf("The Course ID is %d \n", temp->courses_id[0]);
            printf("The Course ID is %d \n", temp->courses_id[1]);
            printf("The Course ID is %d \n", temp->courses_id[2]);
            printf("The Course ID is %d \n", temp->courses_id[3]);
            printf("The Course ID is %d \n", temp->courses_id[4]);
            printf("---------------------------------------- \n");
        }
        temp++;
    }
    if (!flag)
        printf("[ERROR] First Name %s not found \n", temp_text);
    printf("---------------------------------------- \n");
}
// search the list to find a student by his last name
void find_by_last_name()
{
    int flag = 0;
    char temp_text[40];
    student_t *temp;
    temp = Queue_List.tail;
    printf("Enter Student Last Name \n");
    gets(temp_text);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (strcmp(temp->L_Name, temp_text) == 0)
        {
            flag = 1;
            printf("Student First Name is %s \n", temp->F_Name);
            printf("Student Last Name is %s \n", temp->L_Name);
            printf("Student Roll Number is %d \n", temp->roll);
            printf("Student GPA Score is %f \n", temp->GPA_Score);
            printf("The Course ID is %d \n", temp->courses_id[0]);
            printf("The Course ID is %d \n", temp->courses_id[1]);
            printf("The Course ID is %d \n", temp->courses_id[2]);
            printf("The Course ID is %d \n", temp->courses_id[3]);
            printf("The Course ID is %d \n", temp->courses_id[4]);
            printf("---------------------------------------- \n");
        }
        temp++;
    }
    if (!flag)
        printf("[ERROR] Last Name %s not found \n", temp_text);
    printf("---------------------------------------- \n");
}
// search the list to find students inrolled in certain courses
void find_students_by_courses()
{
    int flag = 0;
    int Course_ID;
    char temp_text[40];
    student_t *temp;
    temp = Queue_List.tail;
    printf("Enter Course ID \n");
    gets(temp_text);
    Course_ID = atoi(temp_text);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (temp->courses_id[0] == Course_ID || temp->courses_id[1] == Course_ID || temp->courses_id[2] == Course_ID || temp->courses_id[3] == Course_ID || temp->courses_id[4] == Course_ID)
        {
            flag = 1;
            printf("Student First Name is %s \n", temp->F_Name);
            printf("Student Last Name is %s \n", temp->L_Name);
            printf("Student Roll Number is %d \n", temp->roll);
            printf("Student GPA Score is %f \n", temp->GPA_Score);
            printf("The Course ID is %d \n", temp->courses_id[0]);
            printf("The Course ID is %d \n", temp->courses_id[1]);
            printf("The Course ID is %d \n", temp->courses_id[2]);
            printf("The Course ID is %d \n", temp->courses_id[3]);
            printf("The Course ID is %d \n", temp->courses_id[4]);
            printf("---------------------------------------- \n");
        }
        temp++;
    }
    if (!flag)
        printf("[ERROR] Course ID %d not found \n", Course_ID);
    printf("---------------------------------------- \n");
}
// get the total number of students entered in the system
void total_of_students()
{
    printf("[INFO] The Total number of Students is %d \n", Queue_List.count);
    printf("[INFO] You can add up to %d \n", Queue_List.length);
    printf("[INFO] You can add %d more students \n", Queue_List.length - Queue_List.count);
    printf("---------------------------------------- \n");
}
// delete a certain student by his roll number
void delete_student()
{
    if (is_Empty(&Queue_List) == Queue_empty || is_Empty(&Queue_List) == Queue_Null)
    {
        printf("\n[ERROR] Delete student by roll number failed\n");
        return;
    }
    int flag = 0;
    int Roll_Num;
    student_t *temp = Queue_List.base;
    printf("Enter Student Roll Number which you want to delete \n");
    scanf("%d", &Roll_Num);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (temp->roll == Roll_Num)
        {
            *temp = *(Queue_List.tail);
            Queue_List.count--;
            // Circular Queue Implementation
            if (Queue_List.tail == (Queue_List.base + (Queue_List.length * sizeof(student_t))) && Circular_Queue)
                Queue_List.tail = Queue_List.base;
            else
                Queue_List.tail++;
            flag = 1;
            break;
        }
        else
            flag = 0;
        temp++;
    }
    if (flag)
        printf("[INFO] The Roll Number is removed Successfully \n");
    else
        printf("[ERROR] The Roll Number is not Found \n");
    printf("---------------------------------------- \n");
}
// update the data of a student
void update_student()
{
    int flag = 0;
    int Roll_Num;
    int choice_val;
    student_t *temp = Queue_List.tail;
    printf("Enter Roll Number to update the entry \n");
    scanf("%d", &Roll_Num);
    for (i = 0; i < Queue_List.count; i++)
    {
        if (temp->roll == Roll_Num)
        {
            flag = 1;
            printf("What do you want to update \n");
            printf(" 1.First Name \n");
            printf(" 2.Last  Name \n");
            printf(" 3.GPA Score \n");
            printf(" 4.Roll Number \n");
            printf(" 5.Courses \n");
            scanf("%d", &choice_val);
            switch (choice_val)
            {
            case 1:
                printf("Enter the new First Name \n");
                scanf("%s", &temp->F_Name);
                break;
            case 2:
                printf("Enter the new Last Name \n");
                scanf("%s", &temp->L_Name);
                break;
            case 3:
                printf("Enter the new GPA Score \n");
                scanf("%f", &temp->GPA_Score);
                break;
            case 4:
                printf("Enter the new Roll Number \n");
                int r;
                scanf("%d", &r);
                if (Roll_Check(r) == 1)
                    temp->roll = r;
                else
                    flag = 0;
                break;
            case 5:
                printf("Enter the new courses ID  \n");
                for (i = 0; i < 5; i++)
                {
                    printf("Enter ID for Course Number %d", i + 1);
                    scanf("%d", &temp->courses_id[i]);
                }
                break;
            default:
                printf("Wrong Option \n");
                break;
            }
        }
        else
            temp++;
    }
    if (flag)
        printf("[INFO] UPDATE SUCCESSFULLY \n");
    else
        printf("[ERROR] UPDATE FAILED \n");
    printf("---------------------------------------- \n");
}
// show all students
void show_all_students()
{
    student_t *temp;
    int i;
    if (is_Empty(&Queue_List) == Queue_not_empty)
    {
        temp = Queue_List.tail;
        printf("\n ---------- Students List ---------- \n");
        for (i = 0; i < Queue_List.count; i++)
        {
            printf("Student First Name is %s \n", temp->F_Name);
            printf("Student Last Name is %s \n", temp->L_Name);
            printf("Student Roll Number is %d \n", temp->roll);
            printf("Student GPA Score is %f \n", temp->GPA_Score);
            printf("The Course ID is %d \n", temp->courses_id[0]);
            printf("The Course ID is %d \n", temp->courses_id[1]);
            printf("The Course ID is %d \n", temp->courses_id[2]);
            printf("The Course ID is %d \n", temp->courses_id[3]);
            printf("The Course ID is %d \n", temp->courses_id[4]);
            printf("---------------------------------------- \n");
            temp++;
        }
    }
    else
        return;
}
// Exit_Fun from the system
void Exit_Fun()
{
    printf("Do you want to exit ? y/n  \n");
    int val = getchar();
    if (val == 'y' || val == 'Y')
    {
        exit(0);
    }
    else if (val == 'n' || val == 'N')
        return;
}
// check Roll Number
int Roll_Check(int roll)
{
    student_t *temp;
    int i;
    temp = Queue_List.tail;
    for (i = 0; i < Queue_List.count; i++)
    {
        if (temp->roll == roll)
        {
            printf("[ERROR] Roll Number already exists %d \n", roll);
            printf("---------------------------------------- \n");
            return 0;
        }
        else
        {
            temp++;
        }
    }
    return 1;
}