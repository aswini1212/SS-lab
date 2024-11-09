#include<stdio.h>
#include<stdlib.h>
void main()
{
    int p[100],n,i,j,total=0,head;
    printf("Enter the no of requests:");
    scanf("%d",&n);
    printf("Enter the requests:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the starting head position:");
    scanf("%d",&head);
    for(i=0;i<n;i++)
    {
        total=total+abs(head-p[i]);
        head=p[i];
    }
    printf("Total seek time:%d",total);
}
