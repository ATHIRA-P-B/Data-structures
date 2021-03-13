#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

void Display();
struct node
{
    int data;
    char color;
    struct node *left,*right,*parent;
};
void leftrotation(struct node **root,struct node *X)
{
    if(!X||!X->right)
    return;
    struct node *y=X->right;
    X->right=y->left;
    if(X->right!=NULL)
    X->right->parent=X;
    y->parent=X->parent;
    if(X->parent==NULL)
    (*root)=y;
    else if(X==X->parent->left)
    X->parent->left=y;
    else X->parent->right=y;
    y->left=X;
    X->parent=y;
}
void rightrotation(struct node **root,struct node *y)
{
    if(!y||!y->left)
    return;
    struct node *x=y->left;
    y->left=x->right;
    if(x->right!=NULL)
    x->right->parent=y;
    x->parent=y->parent;
    if(x->parent==NULL)
    (*root)=x;
    else if(y==y->parent->left)
    y->parent->left=x;
    else y->parent->right=x;
    x->right=y;
    y->parent=x;
}
void InsertFixup(struct node **root,struct node *z)
{
  while(z!=*root &&z!=(*root)-> left&& z!=(*root)->right &&z->parent->color=='R')
  {
      struct node *y;
      if(z->parent && z->parent->parent &&z->parent==z->parent->parent->left)
      y=z->parent->parent->right;
      else
      y=z->parent->parent->left;
      if(!y)
      z=z->parent->parent;
      else if(y->color=='R')
      {
          y->color='B';
          z->parent->color='B';
          z->parent->parent->color='R';
          z=z->parent->parent;
      }
      else
      {
          if(z->parent == z->parent->parent->left && z==z->parent->left)
          {
              char ch=z->parent->color;
              z->parent->color=z->parent->parent->color;
              z->parent->parent->color=ch;
              rightrotation(root,z->parent->parent);
          }
          if(z->parent && z->parent->parent &&z->parent==z->parent->parent->left && z==z->parent->right)
          {
              char ch=z->color;
              z->color=z->parent->parent->color;
              z->parent->parent->color=ch;
              leftrotation(root,z->parent);
              rightrotation(root,z->parent->parent);
          }
          if(z->parent &&z->parent->parent && z->parent == z->parent->parent->right && z==z->parent->right)
          {
              char ch=z->parent->color;
              z->parent->color=z->parent->parent->color;
              z->parent->parent->color=ch;
              leftrotation(root,z->parent->parent);
          }
          if(z->parent && z->parent->parent &&z->parent==z->parent->parent->right && z==z->parent->left)
          {
              char ch=z->color;
              z->color=z->parent->parent->color;
              z->parent->parent->color=ch;
              rightrotation(root,z->parent);
              leftrotation(root,z->parent->parent);
          }
        }
    }
  (*root)->color='B';
}
void insert(struct node **root,int data)
{
    struct node *z=(struct node*)malloc(sizeof(struct node));
    z->data=data;
    z->left=z->right=z->parent=NULL;
    if(*root==NULL)
    {
        z->color='B';
        (*root)=z;
    }
    else
    {
        struct node *y=NULL;
        struct node *x=(*root);
        while(x!=NULL)
        {
            y=x;
            if(z->data<x->data)
            x=x->left;
            else
            x=x->right;
        }
        z->parent=y;
        if(z->data>y->data)
        y->right=z;
        else
           y->left=z;
           z->color='R';
           InsertFixup(root,z);
    }
}
void Inorder(struct node *root)
{
    static int last=0;
    if(root==NULL)
    return;
    Inorder(root->left);
    printf("  %d  ",root->data);
    if(root->data<last)
    printf("\nPUTE\n");
    last=root->data;
    Inorder(root->right);
}
int main()
{
    struct node *root=NULL;
    printf("R&B");
    while(1)
    {
        printf("\nEnter operations\n1.Insert  2.Display  3.2D Display  4.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:return 0;
            case 1:{
                printf("Enter data to insert:\n");
                int data;
                scanf("%d",&data);
                insert(&root,data);
            }break;
            case 2:Inorder(root);
            break;
            case 3:Display(root,0);
            break;
            case 4:return 0;
            break;
            default:printf("Please enter valid inputs");
        }
    }
}
void Display(struct node *root,int space)
{
            if(root)
            {
                space+=COUNT;
                Display(root->right,space);
                printf("\n\n");
                for(int i=COUNT;i<space;i++)
                {
                    printf(" ");
                }
                printf("%d(%c)",root->data,root->color);
                Display(root->left,space);
            }
}
            
