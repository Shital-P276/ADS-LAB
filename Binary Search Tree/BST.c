#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct searchtree
{
    int element;
    struct searchtree *left, *right;
} *root;
typedef struct searchtree *node;
typedef int ElementType;
node insert(ElementType, node);
node delete(ElementType, node);
void makeempty();
node findmin(node);
node findmax(node);
node find(ElementType, node);
void display(node, int);
void main()
{
    int ch;
    ElementType a;
    node temp;
    makeempty();
    while (1)
    {
printf("\n1. Insert\n2. Delete\n3. Find\n4. Find min\n5. Find max\n6.Display\n7. 
Exit\nEnter Your Choice : ");
scanf("%d",&ch);
switch(ch)
{
        case 1:
            printf("Enter an element : ");
            scanf("%d", &a);
            root = insert(a, root);
            break;
        case 2:
            printf("\nEnter the element to delete : ");
            scanf("%d", &a);
            root = delete (a, root);
            break;
        case 3:
            printf("\nEnter the element to search : ");
            scanf("%d", &a);
            temp = find(a, root);
            if (temp != NULL)
                printf("Element found");
            else
                printf("Element not found");
            break;
        case 4:
            temp = findmin(root);
            if (temp == NULL)
                printf("\nEmpty tree");
            else
                printf("\nMinimum element : %d", temp->element);
            break;
        case 5:
            temp = findmax(root);
            if (temp == NULL)
                printf("\nEmpty tree");
            else
                printf("\nMaximum element : %d", temp->element);
            break;
        case 6:
            if (root == NULL)
                printf("\nEmpty tree");
            else
                display(root, 1);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice");
}
    }
}
node insert(ElementType x, node t)
{
    if (t == NULL)
    {
        t = (node)malloc(sizeof(node));
        t->element = x;
        t->left = t->right = NULL;
    }
    else
    {
        if (x < t->element)
            t->left = insert(x, t->left);
        else if (x > t->element)
            t->right = insert(x, t->right);
    }
    return t;
}
node delete(ElementType x, node t)
{
    node temp;
    if (t == NULL)
        printf("\nElement not found");
    else
    {
        if (x < t->element)
            t->left = delete (x, t->left);
        else if (x > t->element)
            t->right = delete (x, t->right);
        else
        {
            if (t->left && t->right)
            {
                temp = findmin(t->right);
                t->element = temp->element;
                t->right = delete (t->element, t->right);
            }
            else if (t->left == NULL)
            {
                temp = t;
                t = t->right;
                free(temp);
            }
            else
            {
                temp = t;
                t = t->left;
                free(temp);
            }
        }
    }
    return t;
}
void makeempty()
{
    root = NULL;
}
node findmin(node temp)
{
    if (temp == NULL || temp->left == NULL)
        return temp;
    return findmin(temp->left);
}
node findmax(node temp)
{
    if (temp == NULL || temp->right == NULL)
        return temp;
    return findmax(temp->right);
}
node find(ElementType x, node t)
{
    if (t == NULL)
        return NULL;
    if (x < t->element)
        return find(x, t->left);
    if (x > t->element)
        return find(x, t->right);
    return t;
}
void display(node t, int level)
{
    int i;
    if (t)
    {
        display(t->right, level + 1);
        printf(“ \n”);
        for (i = 0; i < level; i++)
            printf(" ");
        printf("%d", t->element);
        display(t->left, level + 1);
    }
}
