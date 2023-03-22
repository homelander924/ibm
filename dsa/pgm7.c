#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct node *NODE;

int flag;
struct node
{
    int cf;
    int px, py, pz;
    struct node *link;
};

NODE get_node()
{
    NODE x;
    x = (struct node *)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of Memory\n");
        exit(0);
    }
    return x;
}

NODE insert_rear(int cf, int x, int y, int z, NODE head)
{
    NODE temp, cur;
    temp = get_node();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    cur = head->link;
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_poly(NODE head)
{
    int i;
    int px, py, pz;
    int cf;
    printf("\nEnter the coef as -999 to End the Polynomial");
    for (i = 1;; i++)
    {
        printf("\nEnter the %d Term", i);
        printf("Coef=");
        scanf("%d", &cf);
        if (cf == -999)
            break;
        printf("Pow x=");
        scanf("%d", &px);
        printf("Pow y=");
        scanf("%d", &py);
        printf("Pow z=");
        scanf("%d", &pz);
        head = insert_rear(cf, px, py, pz, head);
    }
    return head;
}

int evaluate(NODE head)
{
    int x, y, z, sum = 0;
    NODE poly;
    printf("Enter the Value of x, y and z");
    scanf("%d%d%d", &x, &y, &z);
    poly = head->link;
    while (poly != head)
    {
        sum += poly->cf * pow(x, poly->px) * pow(y, poly->py) * pow(z, poly->pz);
        poly = poly->link;
    }
    return sum;
}

void display(NODE head)
{
    NODE temp;
    if (head->link == head)
    {
        printf("\nPoly Does not Exist\n");
        return;
    }
    temp = head->link;
    while (temp != head)
    {
        printf("+%dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
        temp = temp->link;
    }
    printf("\n");
}

void main()
{
    NODE h1, h2, h3, head;
    int sum;
    int ch;
    // clrscr();
    head = get_node();
    head->link = head;
    h1 = get_node();
    h2 = get_node();
    h3 = get_node();
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    for (;;)
    {
        printf("1:Read Polynomial\n2:Evaluate\n3:Display\n4:Exit\n");
        printf("Enter The Choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The Polynomial\n");
            head = read_poly(head);
            break;
        case 2:
            sum = evaluate(head);
            printf("The Given Polynomial is\n");
            display(head);
            printf("The Result=%d\n", sum);
            break;
        case 3:
            printf("The Given Polynomial is \n");

            display(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
}