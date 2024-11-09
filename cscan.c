#include<stdio.h>
#include<stdlib.h>
void main()
{
    int total,n,i,j,p[100],head,dir,index,temp;
    printf("Enter the no of requests:");
    scanf("%d",&n);
    printf("Enter the requests:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    //sort the requests in ascending order
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            if(p[i]>p[i+1])
            {
            temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
            }
        }
    }
    printf("Enter the direction:");
    scanf("%d",&dir);
    //1 means towards right and 0 means towards the left
    
    printf("Enter the head:");
    scanf("%d",&head);
    
    //finding the index
    for(i=0;i<n;i++)
    {
        if(p[i]>head)
        {
            index=i;
            break;
        }
    }
    
    if(dir==1)
    {
        for(i=index;i<n;i++)
        {
            printf("%d->",p[i]);
            total=total+abs(head-p[i]);
            head=p[i];
        }
        //assuming the size to be 200
        printf("199->0->");
        total=total+(199-p[n-1]);
        total=total+(199-0);
        head=0;
        for(i=0;i<index;i++)
        {
            printf("%d->",p[i]);
            total=total+abs(head-p[i]);
            head=p[i];
        }
    }
    else if(dir==0)
    {
        for(i=index-1;i>=0;i--)
        {
            printf("%d->",p[i]);
            total=total+abs(head-p[i]);
            head=p[i];
        }
        printf("0->199->");
        total=total+(p[0]-0);
        total=total+(199-0);
        head=199;
        for(i=n-1;i>=index;i--)
        {
            total=total+abs(head-p[i]);
            printf("%d->",p[i]);
            head=p[i];
        }
        
    }
    printf("Total head movements:%d",total);
}
