#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5

int item, queue[SIZE];
int front = -1, rear = -1;

int qfull()
{
    if (front == (rear + 1) % SIZE)
        return 1;
    else
        return 0;
}

int qempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void add()
{
    if (qfull())
        printf("\n The Circular Queue is Full\n");
    else
    {
        printf("\n Enter the Element\t:");
        scanf("%d", &item);
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

void del()
{
    if (qempty())
        printf("\n Queue is Empty\n");
    else
    {
        item = queue[front];
        if (front == rear)
            front = rear = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("\n The Deleted Item is %d", item);
    }
}

void display()
{
    int i;
    if (qempty())
    {
        printf("\n The Queue is Empty\n");
        return;
    }
    i = front;
    while (i != rear)
    {
        printf("%d\t", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\t", queue[i]);
}
void main(void)
{
    int choice;
    for (;;)
    {
        printf("\n Main Menu");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\n Enter Your Choice\t:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid Choice");
        }
    }
    getch();
}