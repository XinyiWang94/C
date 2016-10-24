#include <stdio.h>  
#include <stdlib.h>   
int a[10];
int quickone(int low,int high)
{
    int i,j,key;
    i=low;
    j=high;
    key=a[i];
    while(i<j)
    {
        while(a[j]>key&&(j>i)) j=j-1;
        if(j>i)
        {
           a[i]=a[j];
           i=i+1;
        }
        while(a[i]<key&&(j>i)) i=i+1;
        if(j>i)
        {
            a[j]=a[i];
            j=j-1;
        }
    }
    a[i]=key;
    return i;
}
void quick(int low,int high)
{
   int k;
   if(low<high)
   {
       k=quickone(low,high);
       quick(low,k-1);
       quick(k+1,high);
    }
}
main()   
{   
     int i;
      for(i=0;i<10;i++) scanf("%d",&a[i]);
      quick(0,9);
      for(i=0;i<9;i++) printf("%d ",a[i]);
      printf("%d\n",a[9]);
      system("pause");   
}
