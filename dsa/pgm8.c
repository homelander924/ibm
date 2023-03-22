#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
struct node *first, *cur, *prev, *next;
void insertfront()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("enter the node to be inserted \n");
    scanf("%d", &temp->info);
    if (first == NULL)
    {
        first = temp;

        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
}
void insertleft()
{
    int key;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    if (first == NULL)
    {
        printf("list is empty \n");
        return;
    }
    printf("enter the key before which node is to be inserted \n");
    scanf("%d", &key);
    printf("enter the node to be inserted \n");
    scanf("%d", &temp->info);
    prev = NULL;
    cur = first;
    while (cur != NULL)
    {
        if (cur->info == key && cur == first)
        {
            temp->rlink = cur;
            cur->llink = temp;
            first = temp;
            return;
        }
        if (cur->info == key)
        {
            temp->rlink = cur;
            cur->llink = temp;
            temp->llink = prev;
            prev->rlink = temp;
            return;
        }
        prev = cur;
        cur = cur->rlink;
    }
    printf("key not found");
}
void Delete1()
{
    int key;
    printf("enter the node to be deleted \n");
    scanf("%d", &key);
    if (first == NULL)
    {
        printf("list is empty \n");
        return;
    }
    if (first->rlink == NULL)
    {
        if (key == first->info)
        {
            printf("%d node is deleted", key);
            free(first);
            first = NULL;
            return;
        }
        else
        {
            printf("key not found \n");
            return;
        }
    }
    cur = first;
    while (cur != NULL)
    {
        if (cur->info == key)
        {
            if (cur == first)
            {
                first = first->rlink;
                printf("%d node is deleted", key);
                free(cur);
                return;
            }

            if (cur->rlink == NULL)
            {
                prev = cur->llink;
                prev->rlink = NULL;
                printf("%d node is deleted \n", key);

                free(cur);
                return;
            }
            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            printf("%d node is deleted \n", key);
            free(cur);
            return;
        }
        cur = cur->rlink;
    }
    printf("key not found \n");
}
void display()
{
    cur = NULL;
    if (first == NULL)
    {
        printf("list is empty \n");
        return;
    }
    printf("list is: \n");
    cur = first;
    while (cur != NULL)
    {
        printf("%d \t", cur->info);
        cur = cur->rlink;
    }
}
int main()
{
    int ch;
    for (;;)
    {
        printf("\n\n1.insert at front\n2.insert before a node \n3.delete at node\n4.display\n");
        printf("\nenter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertfront();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            Delete1();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}