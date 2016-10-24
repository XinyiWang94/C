#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int converse(char a)
{
   if(a=='('||a==')')           return 1;
   if(a=='+'||a=='-')           return 2;
   if(a=='*'||a=='/'||a=='^')   return 3;
   if(a>=48&&a<=57)             return 4;
   return 0;
}
int note(char a[20])
{
   int l,i,note1=0;
   l = strlen(a);
   for(i=0;i<l;i++)
   {
      if((i!=(l-1))&&a[i]=='('&&a[i+1]==')')             return 0;
      if((i<=l-3)&&a[i]=='('&&a[i+2]==')')               return 0;
      if((i<=l-4)&&a[i]=='('&&a[i+3]==')')               return 0;
      if(i<(l-1)&&a[i]>=48&&a[i]<=57&&a[i+1]=='(')       return 0;
      if(a[i]=='('&&(a[i+1]<48||a[i+1]>57)&&a[i+1]!='(') return 0;
      if((i!=(l-1))&&a[i]==')'&&a[i+1]=='(') return 0;
      if(converse(a[i])==1)       note1=note1+1;
   }
   if(note1%2==1) return 0;
   return 1;
}
int calculate(char x1,int a,int b)
{
    switch(x1)
    {
        case '+': return a+b; 
        case '-': return a-b; 
        case '*': return a*b; 
        case '/': return a/b; 
        case '^': return pow(a,b); 
        case '%': return a%b;
        default : return 0; 
    }
}
int Operate(char a[20]) 
{
    int s=0,i,l,j=0,i1=0,i2=-1,i3=-1,num[20]={0};
    char sign[20]={0},d[20]={0};
    l = strlen(a);
    for(i=0;i<l;i++)
    {
       if(a[i]>=48&&a[i]<=57)  
       {
             d[i1]=a[i];
             i1=i1+1;
             if(i==l-1) 
             {
                i2=i2+1;
                num[i2]=atoi(d); 
             }
       }
       else
       {
             if(i1!=0)
             {
                 d[i1]='\0';
                 i2=i2+1;
                 num[i2]=atoi(d);
                 i1=0;
             }
             if(a[i]=='('||i3!=-1&&(converse(a[i])>converse(sign[i3]))||i3==-1)  
             {
                i3=i3+1;
                sign[i3]=a[i];
             }
             else 
             {
                if(a[i]==')')
                {
                    while(sign[i3]!='(')
                    {
                        num[i2-1]= calculate(sign[i3],num[i2-1],num[i2]);
                        i2=i2-1;
                        i3=i3-1;
                    }
                    i3=i3-1;
                }
                else  
                {
                     num[i2-1]= calculate(sign[i3],num[i2-1],num[i2]);
                     i2=i2-1;
                     sign[i3]=a[i];
                }
             }
       }
    }
    while(i3!=-1)
    {
       if(sign[i3]=='/'&&num[i2]==0)
       {
          printf("Divide 0.\n");
          return 0;
       }
       s=s+calculate(sign[i3],num[i2-1],num[i2]);
       i2=i2-2;
       i3=i3-1;
    }
    return s;
}
main()
{
      int N,i;
      char a[20][20]={0};
      scanf("%d",&N);
      for(i=0;i<N;i++)   scanf("%s",a[i]);
      for(i=0;i<N;i++)   
      {
         if(note(a[i])==1&&Operate(a[i])!=0)  printf("%d\n",Operate(a[i]));
         else if(note(a[i])==0)               printf("error.\n");
      }
      system ("pause");
      return 0;
}

      
                     
                           
