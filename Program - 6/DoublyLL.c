#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
int main()
{
    int ch,n,pos,i;
    typedef struct node NODE;
    NODE *head=NULL,*p;
    NODE *temp;
    while(1)
    {
        printf("\n1. Insert at beginning \n2. Insert at a position \n3. Insert at end\n4. Delete from beginning\n5. Delete from a position \n6.Delete from end \n7. Display \n8 Exit");
        printf("\nEnter the choice:");
        scanf(" %d",&ch);
    
        switch(ch)
        {
        case 1:
        printf("Enter the element:");
        scanf(" %d",&n);
        temp=(NODE*)malloc(sizeof(NODE));
        if(head==NULL)
        {
            temp->prev=NULL;
            temp->next=NULL;
            temp->data=n;
            head=temp;
        }
        else
        {
            p=head;
            temp->data=n;
            temp->next=head;
            p->prev=temp;
            head=temp;
            temp->prev=NULL;
        }
             break;
        case 2 :
        printf("Enter the position:");
        scanf(" %d",&pos);
        printf("Enter the element:");
        scanf(" %d",&n);
        temp=(NODE*)malloc(sizeof(NODE));
        temp->data=n;
        p=head;
        if(pos==1)
        {
            if(head==NULL)
            {
                temp->prev=NULL;
                temp->data=n;
                temp->next=NULL;
                head=temp;
            }
            else
            {
               p=head;
               temp->data=n;
               temp->next=head;
               p->prev=temp;
               head=temp;
               temp->prev=NULL;
            }
        }
            else
            {
                temp->data=n;
                for(i=1;i<=pos-2;i++)
                {
                    p=p->next;
                }
                temp->data=n;
                for(i=1;i<=pos-2;i++)
                {
                    p=p->next;
                }
                temp->next=p->next;
                p->next=temp;
                temp->prev=p;
                p->next->prev=temp;
            }
                  break;
            case 3 :
            printf("Enter the element:");
            scanf(" %d",&n);
            temp=(NODE*)malloc(sizeof(NODE));
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            temp->data=n;
            temp->prev=p;
            temp->next=NULL;
                   break;
            case 4 :
            if(head==NULL)
            {
                printf("List is empty");
            }
            else
            {
                p=head;
                p=p->next;
                p->prev=NULL;
                head=p;
            }
                  break;
            case 5 :
           printf("Enter the position:");
            scanf(" %d",&pos);
            if(pos==1)
            {
                if(head==NULL)
                {
                    printf("List is empty");
                }
                else
                   {
                        p=head;
                        p=p->next;
                        p->prev=NULL;
                        head=p;
                    }
            }
                else
                {
                   p=head;
                   for(i=1;i<pos;i++)
                   p=p->next;
                   if(p->next->next==NULL)
                   {
                       p->next==NULL;
                   }
                   else
                   {
                       p->next=p->next->next;
                       p->next->prev=p;
                   }
                }
                     break;
            
                case 6 :
                p=head;
                if(p->next==NULL)
                {
                    head=NULL;
                }
                else
                 {
                        while(p->next->next!=NULL)
                        {
                        p=p->next;
                    }
                    p->next=NULL;
                 }
                     break;
                case 7 :
                if(head==NULL)
                {
                    printf("list is empty ");
                }
                p=head;
                while(p!=NULL)
                {
                    printf(" %d",p->data);
                    p=p->next;
                }
                     break;
                case 8 :
                       return 0;
                       break;
               default:
                       printf("invalid choice");
               
        

}
    }
}

      

         

