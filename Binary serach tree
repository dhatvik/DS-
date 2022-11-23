
/*
 Purpose: This program does the following:
 a) Creates Binary Search Tree through 'Double Recursion' call to 'CreateBST' function
 b) Ensures that duplicate values are not allowed to be entered in the BST
 c) Displays the BST in three types of traversal
 --- Inorder, Preorder and Postorder methods
 */

#include <stdio.h>
#include<stdlib.h> //for malloc
struct BSTree
{
    int marks;
    struct BSTree *right;
    struct BSTree *left;
};

//Prototype / Forward declarion of the functions
struct BSTree *createBSTree(struct BSTree *, int);
void Inorder(struct BSTree *);
void Preorder(struct BSTree *);
void Postorder(struct BSTree *);

int main()
{
    struct BSTree *root = NULL;
    int choice, value, n, i;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                root = NULL;
                printf("\n\nBST for How Many Nodes ? ");
                scanf("%d",&n);
                for(i = 1; i <= n; i++)
                {
                    printf("\nEnter data for node %d : ", i);
                    scanf("%d",&value);
                    root = createBSTree(root,value);
                }
                printf("\nBST with %d nodes is ready to Use!!\n", n);
                break;
            case 2:
                printf("\nBST Traversal in INORDER \n");
                Inorder(root);
                break;
            case 3:
                printf("\nBST Traversal in PREORDER \n");
                Preorder(root);
                break;
            case 4:
                printf("\nBST Traversal in POSTORDER \n");
                Postorder(root);
                break;
            case 5:
                printf("\n\n Terminating  \n\n");
                exit(0);
                break;
            default:
                printf("\n\nInvalid Option !!! Try Again !! \n\n");
                break;
        }
    } while(choice != 5);
    return 0;
}

struct BSTree *createBSTree(struct BSTree *root, int value)
{
    if(root == NULL)
    {
        root = (struct BSTree *)malloc(sizeof(struct BSTree));
        root->left = root->right = NULL;
        root->marks = value;
        return root;
    }
    else
    {
        //BST hence the new node created must be correctly put to the right or left
        if(value < root->marks )
            root->left = createBSTree(root->left,value);
        else if(value > root->marks )
            root->right = createBSTree(root->right,value);
        else
            //Ensures that duplicate values are not allowed to be entered in the BST
            printf(" Duplicate Element !! Not Allowed !!!");
        
        return(root);
    }
}


void Inorder(struct BSTree *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->marks);
        Inorder(root->right);
    }
}

void Preorder(struct BSTree *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->marks);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct BSTree *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->marks);
    }
}


