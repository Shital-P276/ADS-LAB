#include <stdio.h>
#include <stdlib.h>

struct searchtree {
    int element;
    struct searchtree *left, *right;
};

typedef struct searchtree *node;

node root = NULL;

// Function declarations
node insert(int x, node t);
node delete(int x, node t);
node find(int x, node t);
node findmin(node t);
node findmax(node t);
void display(node t, int level);

// Main function
int main() {
    int choice, value;
    node temp;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Find\n4. Find Min\n5. Find Max\n6. Display\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(value, root);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                root = delete(value, root);
                break;
            case 3:
                printf("Enter element to find: ");
                scanf("%d", &value);
                temp = find(value, root);
                printf(temp ? "Element found\n" : "Element not found\n");
                break;
            case 4:
                temp = findmin(root);
                printf(temp ? "Minimum element: %d\n" : "Tree is empty\n", temp->element);
                break;
            case 5:
                temp = findmax(root);
                printf(temp ? "Maximum element: %d\n" : "Tree is empty\n", temp->element);
                break;
            case 6:
                printf("Tree:\n");
                display(root, 0);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Insert a node
node insert(int x, node t) {
    if (!t) {
        t = (node)malloc(sizeof(struct searchtree));
        t->element = x;
        t->left = t->right = NULL;
    } else if (x < t->element) {
        t->left = insert(x, t->left);
    } else if (x > t->element) {
        t->right = insert(x, t->right);
    }
    return t;
}

// Delete a node
node delete(int x, node t) {
    if (!t) {
        printf("Element not found\n");
        return NULL;
    }

    if (x < t->element) {
        t->left = delete(x, t->left);
    } else if (x > t->element) {
        t->right = delete(x, t->right);
    } else {
        // Node with one or no children
        if (!t->left) {
            node temp = t->right;
            free(t);
            return temp;
        } else if (!t->right) {
            node temp = t->left;
            free(t);
            return temp;
        }

        // Node with two children
        node temp = findmin(t->right);
        t->element = temp->element;
        t->right = delete(temp->element, t->right);
    }
    return t;
}

// Find a node
node find(int x, node t) {
    if (!t || t->element == x)
        return t;
    return (x < t->element) ? find(x, t->left) : find(x, t->right);
}

// Find the minimum value
node findmin(node t) {
    if (!t)
        return NULL;
    return t->left ? findmin(t->left) : t;
}

// Find the maximum value
node findmax(node t) {
    if (!t)
        return NULL;
    return t->right ? findmax(t->right) : t;
}

// Display the tree
void display(node t, int level) {
    if (t) {
        display(t->right, level + 1);
        printf("%*s%d\n", level * 4, "", t->element); // Indented based on tree level
        display(t->left, level + 1);
    }
}
