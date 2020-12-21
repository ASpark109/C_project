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
    insert(50);
    printf("\n");
    insert(70);
    printf("\n");
    insert(10);
    printf("\n");
    insert(25);
    printf("\n");
    insert(65);
    printf("\n");
    insert(90);
    printf("\n");
}