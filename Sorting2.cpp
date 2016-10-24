#include <stdlib.h>
#include <stdio.h>
main()
{
      int n,i,i0,j,i1,n0;
      scanf(" %d",&n);
      int a[n],b[n];
      n0=n;
      for(i=1;i<=n;i++)
      {
          scanf("%d",&a[i-1]);
          }
      if(a[0]>a[1]) 
          {
                     b[0]=a[1]; 
                     b[1]=a[0];
          }
      else  if(a[0]<a[1])         
            {
                     b[0]=a[0]; 
                     b[1]=a[1];
                     }
            else   b[0]=a[0];
      if(a[0]==a[1]) 
      {
                     i0=1;
                     n0=n0-1;
                     }
      else i0=2;
      for(i=2;i<n;i++)
      {
           if(i0==1)
           {
                  if(a[i]>b[0])  b[1]=a[i];
                  else if(a[i]<b[0])
                  {
                       b[0]=a[i];
                       b[1]=a[0];
                       }
                       else n0=n0-1;
                       }
           else 
           {
                for(j=1;j<i0;j++)
           {
               if(a[i]<b[0]) 
               {
                    i1=0;
                    break;
                    }
               if(a[i]>b[i0-1]) 
               {
                       i1=i0;
                       break;
                       }
               if(a[i]>b[j-1]&&a[i]<b[j]) 
               {
                                          i1=j;
                                          break;
               }
               if(a[i]==b[j-1]) 
               {
                                n0=n0-1;
                                break;
                } 
               
           }
               if(a[i]==b[j-1]) continue;
           i0++;
           for(j=i0-1;j!=0;j--)
           {
                if(j>i1) b[j]=b[j-1];
                else if(j=i1) b[j]=a[i];
           }
           if(i1==0) b[0]=a[i]; 
           }
      }
      for(i=1;i<=n0;i++)
      {
          if(i<n0) printf("%d ",b[i-1]);
          else    printf("%d\n",b[i-1]);
          }
      system("pause");
}
      
