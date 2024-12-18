#include <stdio.h>


int front = -1, rear = -1,frame;

int queue[100];

int fault;


void enqueue(int item)

{
    if (rear == 99)
    
{
        printf("Queue is full\n");
    }
    
else
    {
        if (rear == -1 && front == -1)
        
{
            rear = 0;
            front = 0;
        }
        
else
       
 {
            rear++;
        }
       
 queue[rear] = item;
    }
}


void dequeue()

{
    if (front == -1 && rear == -1)
    
{
        printf("Queue is empty\n");
    }
    
else
    {
        if (front == rear)
        
{
            front = -1;
            rear = -1;
        }
        
else
        {
            front++;
        }
    }
}


void display()
{
    if (front == -1 && rear == -1)
    
{
        printf("Queue is empty\n");
    }
    
else
    {
       
 for (int i = front; i <= rear; i++)
        
{
            printf("%d\t", queue[i]);
        }
        
printf("\n");
    }
}


int found(int item)

{
    int flag = 0; 
    
    
for (int i = front; i <= rear; i++) 
    
{
        if (queue[i] == item)
        
{
            flag = 1;
            
break;
        }
        
    }
    
if(flag==0)
    
{
        fault++;
    }
    
return flag;
}


int main()

{
    int  page[100], n;

    
printf("Enter the number of frames: ");
    
scanf("%d", &frame);
    
    
printf("Enter the number of elements in the page sequence: ");
    
scanf("%d", &n);
    
    
printf("Enter the page sequence: ");
    
for (int i = 0; i < n; i++)
    
{
        scanf("%d", &page[i]);
    }
    
    
for (int i = 0; i < n; i++)
    
{
        if (found(page[i]) == 0)
        
{
            if (i < frame)
            
{
                enqueue(page[i]);
            }
            
else
            
{
                dequeue();
                
	enqueue(page[i]);
            }
        }
    }
    
    
printf("Final queue state:\n");
    
display();
    
printf("Page faults:%d",fault);
    
    
return 0;
}
