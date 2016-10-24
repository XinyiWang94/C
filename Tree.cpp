#include <stdio.h>  
#include <stdlib.h>   
typedef struct point
{
   int data;
   struct point* Lchild,*Rchild;
}point;
void read(point *T)
{
   if(T!=NULL)
   {
       read(T->Lchild);
       if(T->data!=0) printf("%d ",T->data);
       read(T->Rchild);
    }
 }
main()   
{   
      point *Tree,*q;
      point *s[15];
      int a[15],i,j;
      for(i=0;i<15;i++)  scanf("%d",&a[i]);
      Tree=(point*)malloc(sizeof(point));
      Tree->data=a[0];
      Tree->Lchild=Tree->Rchild=NULL;
      s[0]=Tree;
 	  for(i=1;i<15;i++)  
      {
          q=(point*)malloc(sizeof(point));
          q->data=a[i];
          q->Lchild=q->Rchild=NULL;
          s[i]=q;
          if((i+1)%2==1) s[(i-1)/2]->Rchild=q;
          else           s[(i-1)/2]->Lchild=q;
      }
      read(Tree);
      printf("\n");
      system("pause");   
}
