#include<stdio.h>

void main()
{
    char name[10][30];
    int start[10],length[10],i,j,k,n,prev_length;
    printf("Enter the no of files:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the name of the file%d",i+1);
        scanf(" %[^\n]",name[i]);
        printf("Enter the starting of file%d",i+1);
        scanf("%d",&start[i]);
        printf("Enter the length of the file%d ",i+1);
        scanf("%d",&length[i]);
    }
    
    for(i=1;i<n;i++)
    {
        prev_length=start[i-1]+length[i-1];
        if(prev_length>start[i])
        {
            start[i]=-1;
            printf("The %s cannot be allocated due to overlapping",name[i]);
        }
    }
    printf("\nFile Allocation Table\n");
    printf("File Name\tStarting block\t Length\n");
    for(i=0;i<n;i++)
    {
        printf("%s   \t%d   \t%d\n",name[i],start[i],length[i]);
        
    }
}
