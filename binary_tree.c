#include <stdio.h>
#include <stdlib.h>
//data structure: binary tree

struct binary_tree
{
    int value;
    struct binary_tree* right;
    struct binary_tree* left;
};

struct binary_tree* head = NULL;
struct binary_tree* ptr = NULL;

struct binary_tree* init()
{
    struct binary_tree* New_node = malloc(sizeof(struct binary_tree));
    New_node->value = 0;
    New_node->left = NULL;
    New_node->right = NULL;
    printf("Init node\n");
    return New_node;
}

void show_tree(struct binary_tree* root)
{
    if (root->left != NULL)
    {
        show_tree(root->left);
    }

    if (root->right != NULL)
    {
        show_tree(root->right);
    }

    printf("%d\n", root->value);
}

int search(int x)
{
    ptr = head;
    
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }

    while (1)
    {
        if (x > ptr->value)
        {
            ptr = ptr->right;
            if (ptr == NULL)
            {
                printf("Not find - %d\n", x);
                return 0;
            }
            
        }

        if (x < ptr->value)
        {
            ptr = ptr->left;
            if (ptr == NULL)
            {
                printf("Not find - %d\n", x);
                return 0;
            }
        }

        if(x == ptr->value)
        {
            printf("find - %d\n", ptr->value);
            return 0;
        }
    }
    
}

int insert(int n)
{
    ptr = head;

    if (head == NULL)
    {
        head = init();
        head->value = n;
        ptr = head;
        printf("Init head\n");
        return 0;
    }

    while (1)
    {
        if (n > ptr->value)
        {
            if (ptr->right != NULL)
            {
                ptr = ptr->right;
                printf("1\n");
            }
            else
            {
                ptr->right = init();
                ptr = ptr->right;
                ptr->value = n;
                printf("2\n");
                return 0;
            }
            
        }

        if (n < ptr->value)
        {
            if (ptr->left != NULL)
            {
                ptr = ptr->left;
                printf("3\n");
            }
            else
            {
                ptr->left = init();
                ptr = ptr->left;
                ptr->value = n;
                printf("4\n");
                return 0;
            }
        }
        
    }
    
}

int main()
{
    insert(5);
    printf("\n");
    insert(6);
    printf("\n");
    insert(4);
    printf("\n");
    insert(7);
    printf("\n");
    insert(3);
    printf("\n");
    insert(8);
    printf("\n");
    insert(2);
    printf("\n");
    insert(9);
    printf("\n");
    insert(1);
    printf("\n");
    insert(10);
    printf("\n");

    show_tree(head);
}