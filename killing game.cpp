#include <stdlib.h>
#include <stdio.h>
typedef struct List
{
   int num;
   struct List* next;
}List;
main()
{
      int t,r,n,i=1,j=0,s=0;
      List *Head,*q,*p;
      scanf("%d %d %d",&t,&r,&n); /*total number*//*start from...*/ /*the died number*/
      q=Head=(List*)malloc(sizeof(List));
      p=(List*)malloc(sizeof(List));
      p->num = 1;    q=p;  p->next=NULL;
      Head->next=p;
      for(i=2;i<=t;i++)
      {
         p=(List*)malloc(sizeof(List));
         p->num = i;     p->next=NULL;   
         q->next=p;      q=p;
      }
      q=p=Head->next;
      for(i=1;i<r;i++) {q=p;  p=p->next;}
      while(Head->next!=NULL&&s<t-1)
      {
         for(i=1;i<n;i++) 
         {
             q=p;
             if(p->next==NULL) p=Head->next;
             else              p=p->next;
         }
         q->next=p->next;
         free(p);
         if(q->next==NULL) p=Head->next;
         else              p=q->next;
         s=s+1;
      }
      printf("%d\n",p->num);
      system ("pause");
}
                    
      
                     
                           
