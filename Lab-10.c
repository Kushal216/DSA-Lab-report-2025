// Write a menu driven program to illustrate basic operations of circular queue having following menu:
// a) Enqueue
// b) Dequeue
// c) Traverse
// d) Exit
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], i;
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    // while (choice != 4)
    printf("Circular Queue Operations\n");
    printf("1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n\n");
Label:
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        printf("Exiting...\n");
        printf("\n\n Program By: KUSHAL DHAKAL");
        exit(0);
    default:
        printf("Invalid!! Please enter Valid choice!!\n\n");
        goto Label;
        break;
    }
    printf("Do you want to Perform the operation?(1 for Yes/0 for No)?");
    scanf("%d", &choice);
    if (choice == 1)
    {
        goto Label;
    }
    return 0;
}
void enqueue()
{
    int item;
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full!!\n\n");
        return;
    }
    else
    {
        printf("Enter the value to Enqueue: ");
        scanf("%d", &item);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {

            rear = (rear + 1) % SIZE; // incremented rear by 1
        }
        queue[rear] = item;
        printf("Enqueue Successfull!!\n\n");
    }
}
void dequeue()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty!!\n\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("Deleted element is: %d\n\n", item);
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("No elements to Display!!\n\n");
        return;
    }
    else
    {
        printf("Queue Elements are:\n");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d\t", queue[i]);
        }
        printf("%d\t", queue[i]);
        printf("\n\n");
    }
}
