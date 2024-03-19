#include "Queue.h"
// here we are using an array of type student of size 50 students...

Queue_status create_queue(Queue_t *q, student_t *queue, unsigned int length)
{
    if (!q || !queue || !length)
    {
        printf("[ERROR] Student Queue Intialization failed");
        return Queue_Null;
    }
    q->base = queue;
    q->head = queue;
    q->tail = queue;
    q->count = 0;
    q->length = length;
    printf("[INFO] Student System Queue Initialization Passed\n");
    return Queue_no_error;
}
Queue_status Enqueue(Queue_t *q, student_t item)
{
    if (!q || !(q->head) || !(q->tail) || !(q->base))
        return Queue_Null;
    if (is_Full(q) == Queue_full)
        return Queue_full;

    *(q->head) = (item);
    // Circular Queue Implementation
    if ((q->head == (q->base + (q->length * sizeof(student_t)))) && Circular_Queue)
        q->head = q->base;
    else
        q->head++;
    q->count++;
    return Queue_no_error;
}
Queue_status Dequeue(Queue_t *q, student_t *item)
{
    if (!(q->head) || !(q->tail) || !(q->base))
        return Queue_Null;
    if (is_Empty(q) == Queue_empty)
        return Queue_empty;

    *item = *(q->tail);
    q->count--;
    // Circular Queue Implementation
    if (q->tail == (q->base + (q->length * sizeof(student_t))) && Circular_Queue)
        q->tail = q->base;
    else
        q->tail++;

    return Queue_no_error;
}
Queue_status is_Empty(Queue_t *q)
{
    if (!(q->head) || !(q->tail) || !(q->base))
        return Queue_Null;
    if (q->count == 0)
        return Queue_empty;
    else
        return Queue_not_empty;
}
Queue_status is_Full(Queue_t *q)
{
    if (!(q->head) || !(q->tail) || !(q->base))
        return Queue_Null;
    if (q->count == q->length)
        return Queue_full;
    else
        return Queue_not_full;
}
void printQueue(Queue_t *q)
{
    student_t *temp;
    int i;
    if (is_Empty(q) == Queue_not_empty)
    {
        temp = q->tail;
        printf("\n ========== Queue_print ========== \n");
        for (i = 0; i < q->count; i++)
        {
            printf("\t %x \n ", *temp);
            temp++;
        }
        printf("            ==========\n");
    }
    else
        return;
}