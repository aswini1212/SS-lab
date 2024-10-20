#include<stdio.h>
#include<stdlib.h>
void main()
{
    int f[100]={0},i,j,k,n,allo,ch,start,n1;
    printf("Enter the blocks that are already allocated:");
    scanf("%d",&n);
    printf("Enter the block numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&allo);
        f[allo]=1;
    }
    while(n>0)
    {
        printf("Enter your choice:\n1.Add File\n2.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the starting block and the no of blocks:\n");
                    scanf("%d",&start);
                    scanf("%d",&n1);
                    if(f[start]==1)
                    {
                        printf("File cannot be allocated");
                        
                    }
                    else
                    {
                        
                        for(j=start;j<start+n1;j++)
                        {
                            
                            if(f[j]==0)
                            {
                                f[j]=1;
                                printf("Blockno:%d---->allocated\n",j);
                            }
                            else
                            {
                                n1++;
                            }
                        }
             
                    }
                    break;
            case 2:
                    exit(0);
                    
        }
    }
}
