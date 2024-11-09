#include<stdio.h>
struct process
{
    int id,at,bt,tat,ct,wt;
};
struct process p[100],temp;
void main()
{
    int n,i,j;
    printf("Enter the no of process:");
    scanf("%d",&n);
    printf("Enter the id,at and bt of each process:");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
    }
    //sorting according to arrival time
     for(j=1;j<n;j++)
     {
         for(i=0;i<n-j;i++)
         {
             if(p[i].at>p[i+1].at)
             {
                 temp=p[i];
                 p[i]=p[i+1];
                 p[i+1]=temp;
             }
         }
     }
     //finding the order of execution
     int min,ct=0;
     for(i=0;i<n;i++)
     {
         min=i;
         for(j=i+1;j<n;j++)
         {
             if(p[j].bt<p[min].bt&&p[j].at<=ct)
             {
                 min=j;
             }
         }
         ct=ct+p[min].bt;
         temp=p[i];
         p[i]=p[min];
         p[min]=temp;
     }
     
     
     p[0].ct=p[0].at+p[0].bt;
     p[0].tat=p[0].ct-p[0].at;
     p[0].wt=p[0].tat-p[0].bt;
     
     for(i=1;i<n;i++)
     {
         if(p[i-1].ct<p[i].at)
         {
             p[i].ct=p[i].at+p[i].bt;
         }
         else if(p[i-1].ct>=p[i].at)
         {
             p[i].ct=p[i-1].ct+p[i].bt;
         }
         p[i].tat=p[i].ct-p[i].at;
         p[i].wt=p[i].tat-p[i].bt;
     }
     
     //arranging the process according to ID
     for(j=1;j<n;j++)
     {
         for(i=0;i<n-j;i++)
         {
             if(p[i].id>p[i+1].id)
             {
                 temp=p[i];
                 p[i]=p[i+1];
                 p[i+1]=temp;
             }
         }
     }
     
     printf("\nSJF\n");
     printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
     for(i=0;i<n;i++)
     {
         printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
     }
}