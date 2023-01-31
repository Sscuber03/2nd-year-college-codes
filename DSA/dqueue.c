#include <stdio.h>   

#define size 5  

int deque[size];    
int f = -1, r = -1;    

void insert_front(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        f=r=0;    
        deque[f]=x;    
    }    
    else if(f==0)    
    {    
        f=size-1;    
        deque[f]=x;    
    }    
    else    
    {    
        f=f-1;    
        deque[f]=x;    
    }    
}    
      
void insert_rear(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else if(r==size-1)    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else    
    {    
        r++;    
        deque[r]=x;    
    }    
    
}    
      
void display()    
{    
    int i=f;    
    printf("\nElements in a deque are: ");    
    while(i!=r)    
    {    
        printf("%d ",deque[i]);    
        i=(i+1)%size;    
    }    
    printf("%d",deque[r]);    
}       
  
void delete_front()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d", deque[f]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(f==(size-1))    
     {    
         printf("\nThe deleted element is %d", deque[f]);    
         f=0;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", deque[f]);    
          f=f+1;    
     }    
}    

void delete_rear()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d", deque[r]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(r==0)    
     {    
         printf("\nThe deleted element is %d", deque[r]);    
         r=size-1;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", deque[r]);    
          r=r-1;    
     }    
}    
    
int main()    
{    
    printf("\nEnter 1 to insertfront\n");
    printf("Enter 2 to deletFront\n");
    printf("Enter 3 to insertRare.\n");
    printf("Enter 4 to deltRare\n");
    printf("Enter 5 to display\n");
    printf("Enter other to stop\n");
    char c;
    int ele,temp=1;
    while(temp){
        printf("\nEnter choise:");
        scanf(" %c",&c);
        switch(c){
            
            case '1': printf("Enter element to insert:");
                      scanf("%d",&ele);
                       insert_front(ele);
                       break;
            
            case '2':delete_front();
                     break;
            
            case '3':printf("Enter element to insert:");
                       scanf("%d",&ele);
                       insert_rear(ele);
                       break;
            
            case '4':delete_rear();
                     break;
            
            case '5': display();
                   break;
            default: temp=0;
                   break;
        } 
    }
    return 0;    
}     

