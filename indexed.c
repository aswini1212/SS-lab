#include<stdio.h>
#include<stdlib.h>
struct file
{
    int index,nblock,block[100];
};
struct file f[100];

void main()
{
    int n,i,j,n1,index;
    printf("Enter the no of files:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the index of file%d",i+1);
        scanf("%d",&f[i].index);
        printf("Enter the no of blocks in file%d",i+1);
        scanf("%d",&f[i].nblock);
        printf("Enter the value of blocks in file%d",i+1);
        for(j=0;j<f[i].nblock;j++)
        {
            scanf("%d",&f[i].block[j]);
        }
        
    }
    
    while(1)
    {
        printf("Enter your choice:\n1.Get blocks\n2.Exit");
        scanf("%d",&n1);
        switch(n1)
        {
            case 1 : printf("Enter the file number: \n");
                     int m;
                     scanf("%d", &m);
                     printf("Blocks allocated: ");
                     for (int i = 0; i < f[m].nblock; i++)
                        {
                            printf("%d\t", f[m].block[i]);
                        }
                     break;
            case 2: exit(0);         
        }
    }
}
