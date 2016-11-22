#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX 104

char answer[MAX];
char guess[MAX];
int alpha[MAX];

int main()
{
    int a, i, j;
    while (scanf("%d", &a) && a != -1)
    {
          getchar();
          int flag, stroke = 0;
          memset(alpha, 1, MAX);
          gets(answer);
          gets(guess);
          printf("Round %d\n", a);
          for (i = 0; i < strlen(guess); i++)
          {
              flag = 0;
              if (alpha[guess[i] - 'a'])
              {
                  for (j = 0; j < strlen(answer); j++)
                      if (guess[i] == answer[j])
                      {
                          answer[j] = '0';
                          flag = 1;
                      }
                  alpha[guess[i] - 'a'] = 0;
                  if (!flag)   
                     stroke++;
              }
              
              if (stroke == 7)
              {
                 printf("You lose.\n");
                 flag = 1;
                 break;         
              }
              
              flag = 1;
              for (j = 0; j < strlen(answer); j++)
               {
                      if (answer[j] != '0')
                      {
                         flag = 0;
                         break;
                      }
               }
               if (flag)
               {
                  printf("You win.\n");
                  break;
               }
          }
          if (!flag)
             printf("You chickened out.\n");
    }
    return 0;
}
