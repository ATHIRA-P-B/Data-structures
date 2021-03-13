#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node *right;
};
struct node *newnode(int item)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=item;
temp->left=temp->right=NULL;
return temp;
}
void traversetree(struct node *root)
{
    if(root !=NULL)
    {
        traversetree(root->left);
        printf("%d\t",root->data);
        traversetree(root->right);
    }
}
struct node *search(struct node* root,int data)
{
    if(root==NULL || root->data==data)
    return root;
    if(root->data<data)
    return search(root->right,data);
    return search(root->left,data);
}
struct node *insert(struct node* node,int data)
{
    if(node==NULL)
    return newnode(data);
    if(data<node->data)
    node->left=insert(node->left,data);
    else if(data>node->data)
    node->right=insert(node->right,data);
    return node;
}
struct node *minValueNode(struct node *node)
{
    struct node *current=node;
    while(current && current->left!=NULL)
    current=current->left;
    return current;
}
struct node *delete(struct node*root,int data)
{
    if(root==NULL)
    return root;
    if(data<root->data)
    root->left=delete(root->left,data);
    else if(data>root->data)
    root->right=delete(root->right,data);
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}
int main()
{
    struct node *root=NULL;
    root=insert(root,23);
    insert(root,15);
    insert(root,12);
    insert(root,17);
    insert(root,32);
    insert(root,29);
    insert(root,45);
    printf("\n\n\nThe tree is:");
    traversetree(root);
    printf("\n\n\nDelete 15");
    if(delete(root,15))
    printf("\n\n\nAfter deletion: ");
    traversetree(root);
    printf("\n\n\nSearching for the element 32:");
    if(search(root,32))
    printf("\n\n\nElement found.\n.");
    else
      printf("\n\n\nElement not found.\n");
      return 0;
}
     
