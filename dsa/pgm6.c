#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node *NODE;

struct node
{
    int info;
    struct node *link;
};

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("out of memory\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}

NODE insert_front(int item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("Link is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("The deleted item is %d \n", temp->info);
    free(temp);
    return first;
}

NODE insert_rear(int item, NODE first)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur = first, prev = NULL;
    if (cur == NULL)
    {
        printf("Link is empty\n");
        return first;
    }
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    freenode(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first)
{
    NODE temp = first;
    if (first == NULL)
    {
        printf("NO NODES IN THE LIST!!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}

void main()
{
    NODE first = NULL;
    int choice, item;
    // clrscr();
    for (;;)
    {
        printf("\n1.INSERT FRONT\n2.INSERT REAR\n3.DELETE FRONT\n4.DELETE REAR\n5.DISPLAY\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            first = insert_front(item, first);
            break;
        case 2:
            printf("Enter the item\n");
            scanf("%d", &item);
            first = insert_rear(item, first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;

        case 5:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}