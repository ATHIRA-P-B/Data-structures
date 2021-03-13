#include<stdio.h>
#define maxsize 25
void cqinsert();
void cqsearch();
void cqdelete();
void cqdisplay();
void cqfele();
void cqrele();
int front=-1,rear=-1;
int q[maxsize];
void main()
{
  int ch,n;
  
  printf("Enter the no of elements:");
  scanf("%d",&n);
  printf("\nOperations on circular queue:");
  while(ch!=7)
  {
   printf("\n1.INSERT\n2.SEARCH\n3.DELETE\n4.DISPLAY \n5.FRONT ELEMENT\n6.REAR ELEMENT\n7.Exit");
   printf("\nEnter the choice:");
   scanf("%d",&ch);
   switch(ch)
    {
    case 1:{
	    cqinsert();
	    break;
	    }
	case 2:{
	    cqsearch();
	    break;
	    }
    case 3:{
	    cqdelete();
	    break;
	    }
	    
    case 4:{
	    cqdisplay();
	    break;
	    }
    case 5:{
	    cqfele();
	    break;
	    }
    case 6:{
	    cqrele();
	    break;
	    }
    case 7:{
	   printf("\nExiting");
	   break;
	   }
    default:printf("\nInvalid choice");
    }
    };
    
    }
    void cqinsert()
    {
     int item;
     printf("\nEnter the element:");
     scanf("%d",&item);
     if(front==0 && rear==(maxsize-1))
      {
      printf("\nOverflow");
      return;
      }
      else
      {
      rear=(rear+1) % maxsize;
      q[rear]=item;
      }
      if(front==-1)
       front=0;
     printf("\nElement inserted");
     }
     void cqsearch()
     {
         int item,i,c=0;
         printf("\n Enter the element you want to search: ");
         scanf("%d",&item);
         for(i=front;i<=rear;i++)
         {
             if(item==q[i])
               {
                 printf("\nThe element was found at:%d ",i+1);
                 c++;
               }
         }
             if(c==0)
             {
                 printf("\nThe element does not exist in the queue. ");
             }
             else
             {
                 printf("\nThe item is present %d times",c);
             }
         
         
     }
     void cqdelete()
     {
      int item;
      if(front==-1)
      {
      printf("\nUnderflow");
      return;
      }
      else
      {
      item=q[front];
      if(front==rear)
      {
      front=-1;
      rear=-1;
      }
      else
       front=(front+1) % maxsize;
       }
      printf("Element deleted is %d",item);
      }
      void cqdisplay()
      {
       int i;
       if(rear==-1)
	printf("\nEmpty queue");
       else
	{
	 printf("\nThe elements are:");
	 for(i=front;i<=rear;i++)
	 {
	  printf("%d\t",q[i]);
	  }
	 }
	 }
	void cqfele()
	{
	int item;
	if(front==-1)
	 printf("\nEmpty queue");
	else
	{
	item=q[front];
	printf("\nThe front element is %d",item);
	}
	}
	void cqrele()
	{
	int item;
	if(rear==-1)
	printf("\nEmpty queue");
	else
	{
	item=q[rear];
	printf("The rear element is %d",item);
	}
	}