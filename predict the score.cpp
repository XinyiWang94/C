#include <stdlib.h>
#include <stdio.h>
main()
{
      int score,time1,time2,time3,i,answer,more,grade,j,grade0;
      for(i=1;;i++)
      {
          printf("How much score do you want in C?\n");
          while(1)
          {
             scanf("%d",&score);
             if(score>=0&&score<=100) break;
             printf("How much score do you want in C?\n");
             }
          if(score<60) printf("Oh my god! Can you have a better goal? Even god can not help you either!Try again!\n");
          else break;
          }
      if(score==100) printf("Good job! You can not be a good student if you don't want 100!\n");
      else 
      {
           if(score==60) printf("You think even one point more is wasteful, don't you? orz...\n");
           else if(score>60&&score<80) 
                {
                         for(i=1;;i++)
                         {
                               if(score>60&&score<80) printf("Do you want more?Y or F?\n");
                               else break;
                               while(1)
                               {
                                     scanf(" %c",&answer);
                                     if(answer=='F'||answer=='Y') break;
                                     printf("Do you want more?Y or F?\n");
                                     }
                               if(answer=='F') 
                               {
                                   printf("Ok...You are easy to be satisfied!\n");
                                   break;
                                   }
                               else 
                               {
                                    printf("How much more?\n");
                                    while(1)
                                    {
                                         scanf("%d",&more);
                                         if(more>=0&&more<=100-score) break;
                                         printf("How much more?\n");
                                         }
                                    score=score+more;
                                    }
                         }
                }
                else printf("That is a reasonable score,you may be a deligiant student!\n");
      }
      grade0=score/10-5;
      printf("Now let's see if you deserve it~\nWe have 15 lessons in all and how many lessons do you have on your C?\n");
      while(1)
      {
              scanf("%d",&time1);
              if(time1>=0&&time1<=15) break;
              printf("We have 15 lessons in all and how many lessons do you have on your C?\n");
              }
      printf("Only listenning the lessons is not enough!\nHow much homework do you finish on your own?\nPlese print the percentage from 0 to 100\n");
      while(1)
      {
              scanf("%d",&time2);
              if(time2>=0&&time2<=100) break;
              printf("How much homework do you finish on your own?\nPlese print the percentage from 0 to 100\n");
              }
      printf("How much time(hours) have you spent on your revision of C?\n");
      while(1)
      {
              scanf("%d",&time3);
              if(time3>=0) break;
              printf("How much time(hours) have you spent on your revision of C?\n");
              }
      time2=time2+time3*2;
      if(time2>100) time2=100;
      if(time1 < 5&&time2<=20) grade=0;
      if(time1>= 5&&time2>=20) grade=1;
      if(time1>= 7&&time2>=40) grade=2;
      if(time1>=10&&time2>=60) grade=3;
      if(time1>=13&&time2>=90) grade=4;
      if(time1==15&&time2==100) grade=5;
      if(grade==0) printf("Turn to beg your teacher,may be you will be saved if he is a Christian!\n");
      else if(grade==grade0) printf("You almose get it!Come on!\n");
           else if(grade>grade0) printf("Congraduations!You deserve it!\n");
                else printf("You are day-dreaming!Go on your revision!!\n");
      system ("pause");
}
                    
      
                     
                           
