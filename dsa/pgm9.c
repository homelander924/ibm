#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
void insert();
void preorder();
void postorder();
void inorder();
void search();
void main()
{
    int ch, res = 1, key;
    NODE temp, root;
    NODE get_node();
    // clrscr();
    root = NULL;
    printf("\nProgram for BST\n");
    for (;;)
    {
        printf("\n1:Insert\n2:Search\n3:Traversal\n4:Exit");
        printf("\nEnter The Choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            do
            {
                temp = get_node();
                printf("\nEnter Element:\t");
                scanf("%d", &temp->info);
                if (root == NULL)
                    root = temp;
                else
                    insert(root, temp);
                printf("\nDo you Want To Insert Next..?(1|0):\t");
                scanf("%d", &res);
            } while (res);
            break;
        case 2:
            printf("\nEnter The Element to be Search:\t");
            scanf("%d", &key);
            search(root, key);
            break;
        case 3:
            if (root == NULL)
                printf("\nTree is not Created");
            else
            {
                printf("\nThe Inorder Traversal\n");
                inorder(root);
                printf("\nThe Preorder Traversal\n");
                preorder(root);
                printf("\nThe Postorder Traversal\n");
                postorder(root);
            }
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
NODE get_node()
{
    NODE temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void insert(NODE root, NODE temp)
{
    if (temp->info < root->info)
    {
        if (root->llink == NULL)
            root->llink = temp;
        else
            insert(root->llink, temp);
    }
    if (temp->info > root->info)
    {
        if (root->rlink == NULL)
            root->rlink = temp;
        else
            insert(root->rlink, temp);
    }
}
void search(NODE root, int key)
{
    if (root == NULL)
        printf("Search Unsuccessful\n");
    else if (key == root->info)
        printf("Search Success Item %d Found", key);
    else if (key < root->info)
        search(root->llink, key);
    else
        search(root->rlink, key);
}
void inorder(NODE temp)
{
    if (temp != NULL)
    {
        inorder(temp->llink);
        printf("%d\t", temp->info);
        inorder(temp->rlink);
    }
}
void preorder(NODE temp)
{
    if (temp != NULL)
    {
        printf("%d\t", temp->info);
        preorder(temp->llink);

        preorder(temp->rlink);
    }
}
void postorder(NODE temp)
{
    if (temp != NULL)
    {
        postorder(temp->llink);
        postorder(temp->rlink);
        printf("%d\t", temp->info);
    }
}