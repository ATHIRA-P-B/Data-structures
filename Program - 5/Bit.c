#include<stdio.h>
void input();
void output();
void setunion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0,0};
int main()
{
    int ch,wish;
    do
    {
        printf("\n------MENU------\n");



        printf("1.Input\n2.Union\n3.Intersection\n4.Difference\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:input();
                break;
            case 2:setunion();
                break;
            case 3:intersection();
                break;
            case 4:difference();
                break;
        }
         
        printf("\nDo you wish to continue?(1/0)\n");
        scanf(" %d",&wish);
    
    }while(wish==1);
}
void input()
{
    int n,m,x,i;
    printf("\nEnter the size of 1st set:");
    scanf(" %d",&n);
    printf("\nEnter the elements:\t");
    for(i=1;i<=n;i++)
    {
        scanf(" %d",&x);
        a[x]=1;
    }
    printf("\n1st set:\t");
    for(i=1;i<=9;i++)
    {
        printf(" %d     ",a[i]);
    }

    printf("\nEnter the size of 2nd set:");
    scanf(" %d",&n);
   
    printf("\nEnter the elements:\t");
    for(i=1;i<=n;i++);
    {
        scanf(" %d",&x);
        b[x]=1;
    }
  
    printf("\n2nd set:\t");
    for(i=1;i<=9;i++)
    {
        printf(" %d     ",b[i]);
    }
    
}

void output(int c[])
{
    int i;
    printf("\n set is ");
    for(i=1;i<=9;i++)
    {
        if(c[i]!=0)
        printf(" %d",i);
        }
}
void setunion()
{
    int i,c[10];
    for(i=1;i<=9;i++)
    {
        if(a[i]!=b[i])
        c[i]=1;
        else 
        c[i]=a[i];
    }
    for(i=1;i<=9;i++)
    {
        printf(" %d",c[i]);
    }
    output(c);
}
void intersection()
{
    int i,c[10];
    for(i=1;i<=9;i++)
    {
        if(a[i]==b[i])
        c[i]=a[i];
        else
        c[i]=0;
    }
    for(i=1;i<=9;i++)
    {
        printf(" %d",c[i]);
    }
    output(c);
}
void difference()
{
    int i,c[10];
    for(i=1;i<=9;i++)
    {
        if(a[i]==1 && b[i]==0)
        c[i]=1;
        else 
        c[i]=0;
    }
    for(i=1;i<=9;i++)
    {
        printf(" %d",c[i]);
    }
    output(c);
}
