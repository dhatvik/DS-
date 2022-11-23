#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int n,i,temp;
    clock_t start,end;
    printf("Enter number of items\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int)rand();
    }
    printf("Before Sorting ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    start=clock();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    end=clock();
    double time=(end-start)/CLOCKS_PER_SEC;
    
    printf("\nAfter Sorting ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime Taken %f\t",time);
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int n,min,i,temp;
    clock_t start,end;
    printf("Enter number of items\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int)rand();
    }
    printf("Before Sorting ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    start=clock();
    for(int i=0;i<n;i++)
    {   min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }    
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    end=clock();
    double time=(end-start)/CLOCKS_PER_SEC;
    
    printf("\nAfter Sorting ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime Taken %f\t",time);
}
