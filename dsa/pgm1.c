#include <stdio.h>
#include <stdlib.h>
int i, a[50], n = 0, POS, ELEM;
void create();
void display();
int insert();
int del();
int main()
{
    int choice;
    do
    {
        printf("\nMENU\n");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.Insert");
        printf("\n 4.delete");
        printf("\n 5.Exit");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            if (n == 0)
            {
                printf("\tArray is empty ");
            }
            else
            {
                insert();
            }
            break;
        case 4:
            if (n == 0)
            {
                printf("\tArray is empty ");
            }
            else
            {
                del();
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\tInvalid Chioce");
        }
    } while (choice != 5);
    return 0;
}

void create()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display()
{
    if (n == 0)
    {
        printf("\tArray is empty ");
    }
    else
    {
        printf("Array elements are \n");
        for (i = 0; i < n; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}

int insert()
{
    printf("Enter the location where you wish to insert an element:\t");
    scanf("%d", &POS);

    if (POS == 0 || POS > n + 1)
    {
        printf("Insertion is not possible 'POS>N'");
    }
    else
    {
        printf("\nEnter the value to Insert: \t");
        scanf("%d", &ELEM);
        for (i = n - 1; i >= POS - 1; i--)
        {
            a[i + 1] = a[i];
        }
        a[POS - 1] = ELEM;
        n++;
    }
    return 0;
}

int del()
{
    printf("Enter the location where you wish to delete element:\t");
    scanf("%d", &POS);
    if (POS == 0 || POS >= n + 1)
    {
        printf("\nDeletion is not possible 'POS>N'");
    }
    else
    {
        printf("\nDeleted Item is = %d\n", a[POS - 1]);
        for (i = POS - 1; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
    return 0;
}