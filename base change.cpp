#include <stdio.h>    
#include <stdlib.h>  
#include <math.h>    
main()      
{      
      long i,j,s1,j1,s2,j2,t,k,i0,j0,i2,i1,tr;
      char a[20],b[20],m; 
      t=0;
      i0=13;
    for(i=0;i<13;i++)
      {
                 if(i<i0)
                 {
                         m=getchar();
                        if(m!=32) a[i]=m;    /*读入第一个数*/
                        else i0=i;
                        }
                 if(i>i0) 
                 {
                          m=getchar();
                          if(m==32) 
                          {
                                    i=i-1;   /*遇到多个空格跳过*/ 
                                    continue;
                                    }
                          else
                          {
                                  if(m>=48&&m<=57||m>=65&&m<=90) b[i-i0-1]=m;
                                  else 
                                    {
                                        j0=i-i0-1;      /*读入第二个数*/
                                        break;
                                    }
                          }
                 }
      }  
      t=0;
      for(i=2;i<=36;i++)   /*第一个数的数制循环*/
      {   
            if(i==30) 
            {
                      tr=0;
                      }
            s1=0;
           for(j1=0;j1<i0;j1++)
           {
                       if(a[j1]>=48&&a[j1]<=57) k=a[j1]-48;
                       else if(a[j1]>=65&&a[j1]<=90) k=a[j1]-55;   /*计算结果*/
                            else break;
                       if(k>=i) break;
                       s1=s1+k*pow(i,i0-j1-1); 
                       } 
                       
           if(k>=i) continue;
           for(j=2;j<=36;j++)
           {
                                                                  /*第二个数的数值*/
                       s2=0;
                       for(j2=0;j2<j0;j2++)
                       {
                       if(b[j2]>=48&&b[j2]<=57) k=b[j2]-48;
                       else if(b[j2]>=65&&b[j2]<=90) k=b[j2]-55;
                            else break;
                       if(k>=j) break;
                       s2=s2+k*pow(j,j0-j2-1);  
                       }  
                       if(k>=j) continue;    /*超过数制跳过*/
                       if(s1==s2)    
                        {
                               for(i2=0;i2<i0;i2++)
                               {
                                    printf("%c",a[i2]);
                               }
                               printf("%c(base%c%d) = ",32,32,i);
                               for(i1=0;i1<j0;i1++)
                               {
                                    printf("%c",b[i1]);
                               }
                               printf("%c(base%c%d)\n",32,32,j);
                               t=1;
                               break;    /*遇到一个找到最小的即可*/
                         }
          }   
      if(t==1) break;   
      }
      if(t==0) 
      {
              for(i=0;i<i0;i++)
                        {
                               printf("%c",a[i]);
                        }                                          /*无符合要求的*/
             printf(" is not equal to ");
             for(i=0;i<j0;i++)
                        {
                               printf("%c",b[i]);
                        }
             printf(" in any base 2..36\n");
      } 
       system("pause");      

}  
