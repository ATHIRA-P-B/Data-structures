#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void BFS(int v)
{
 for(i=1;i<=n;i++)
   if(a[v][i] && !visited[i])
     q[++r]=i;
   if(f<=r)
   {
   visited[q[f]]=1;
   printf("%d\t",q[f]);
   BFS(q[f++]);
   }
}
void main()
{
int v;
printf("ENTER THE NO OF VERTICES:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 q[i]=0;
 visited[i]=0;
}
printf("\nENTER GRAPH DATA IN MATRIX FORM:\n");
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  scanf("%d",&a[i][j]);
printf("\nENTER THE STARTING VERTEX:");
scanf("%d",&v);
visited[v]=1;
printf("%d",v);
BFS(v);
}