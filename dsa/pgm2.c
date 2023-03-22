#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

void push();
void pop();
void display();

int stk[MAX_SIZE], top = -1;

void main()
{
    int choice;
    while (1)
    {
        printf("\n\nMENU:");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.exit");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice); // Read Choice
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\tInvalid Chioce");
        }
    }
}

void push()
{
    int p;
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("Enter the Element to Push\n");
        scanf("%d", &p);
        top++;
        stk[top] = p;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Poped element is %d", stk[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Elements in STACK are \n");
        for (i = 0; i <= top; i++)
        {
            printf("%d\t", stk[i]);
        }
    }
}