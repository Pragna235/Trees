#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};

struct tree
{
    int data;
    struct tree *left, *right;
};

struct node* create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter -1 to stop creating new node!");
    printf("\nEnter value of x: ");
    scanf("%d",&x);

    if(x==-1)
        return 0;
    newnode->data=x;
    printf("\nEnter left child node value: ");
    newnode->left=create();
    printf("\nEnter right child node value : ");
    newnode->right=create();
    return newnode;
};

void inorder( struct tree *root)
{


   if (root==NULL)
   {
       return ;
   }
   else
   {
      inorder(root->left);
      printf("%d\t",root->data);
      inorder(root->right);
    }

}

void preorder(struct tree *root)
{

   if(root == NULL)
      return;


   else
   {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);

   }


}

void postorder(struct tree *root)
{
    if(root==NULL)
        return;
    else
        {
            postorder(root->left);
            postorder(root->right);
            printf("%d\t",root->data);
        }

}

void main()
{
    struct node *root=0,*ptr=0;
    root=create();
    printf("\nInorder Traversal!\n");
    inorder(root);
    printf("\nPreorder Traversal!\n");
    preorder(root);
    printf("\nPostorder Traversal!\n");
    postorder(root);
}
