// test-seven.cpp : 定义控制台应用程序的入口点。
//

// poj-进制转换练习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h>  
char str1[500], str2[500], quto[500];  //str1保存输入，str2保存输出，quto保存商  
int char_2_int(char c){  //字符映射到整数  
    int n;  
    if(c >= '0' && c <= '9') n = c-'0';  
    else if(c >= 'A' && c <= 'Z') n = c-'A'+10;  
    else n = c-'a'+36;  
    return n;  
}  
char int_2_char(int n){  //整数映射到字符  
    char c;  
    if(n >= 0 && n <= 9) c = n+'0';  
    else if(n >= 10 && n <= 35) c = n+'A'-10;  
    else c = n+'a'-36;  
    return c;  
}  
/*
int main(){  
    int b1, b2, n, s, cur, last, top;  //b1为转换前进制，b2为转换后进制  
    int t, quit;  
    int i, j, k;  
    scanf("%d", &t);  
    for(k = 0; k < t; k++){  
        scanf("%d%d%s", &b1, &b2, str1);  
        printf("%d %s\n%d ", b1, str1, b2);  
        top = 0;  
        quit = 0;  
        while(!quit){  
            last = 0;  
			//将b1进制转换为b2进制的方法为求商取余的循环至商为0 除的时候被除数的值需要为10进制
            for(i = 0; i < strlen(str1); i++){  //一次求商取余（关键） str1除b2进制数得余数 再将商做被除数对b2继续取余  直到商为0 
				//cur为当前得到的10进制数 last为上次i-1位得到的余数
                cur = last*b1+char_2_int(str1[i]);  //对输入数从高位开始进行逐位加权累加，存入cur  
                if(cur < b2){  //若cur的值小于基b2，则继续累加，且记商的对应位为0  
                    last = cur;  
                    quto[i] = '0';  
                    continue;  
                }  
                else{  //若cur的值大于基b2，则进行除法运算，保存商的对应位，本次余数纳入加权累加中  
                    quto[i] = int_2_char(cur/b2);  
                    last = cur%b2;  
                }  
            }  
			//quto[]为商 
            quto[i] = '\0';  
            quit = 1;  
            for(j = 0; j < strlen(quto); j++)  //检测商是否为0，若为0则表示转换完毕，结束循环  
                if(quto[j] != '0') quit = 0;  
			//余数放入str2[]中  最后需要逆序输出
            str2[top++] = int_2_char(last);  //
			//商quto[]将作为新的被除数 过滤高位0
            for(s = 0; s < strlen(quto); s++)  
                if(quto[s] != '0') break;  
            for(i = s; i < strlen(quto); i++)  //将本次除法运算的商作为新的被除数  
                str1[i-s] = quto[i];  
            str1[i-s] = '\0';  
        }  
        for(int i = top-1; i >= 0; i--)  //逐位逆推得转换后的新数  
            printf("%c", str2[i]);  
        printf("\n\n");  
    }  
    return 0;  
}
*/
int main()
{
	int b;
	int i,j,s;
	scanf("%d",&b);
	scanf("%s",str1);
	printf("%d %s\n",b,str1);
	printf("10 is:\n");
	int last = 0;
	int ok = 0;
	int top = 0;
	int cur = 0;
	while(!ok)
	{
		last = 0;
		for(i = 0;i<strlen(str1);i++)
		{
			cur = last*b+char_2_int(str1[i]);
			if(cur<10)
			{
				last = cur;
				quto[i] = '0';
				continue;
			}
			else
			{
				quto[i] = int_2_char(cur/10);
				last = cur%10;
			}
		}
		quto[i] = '\0';
		ok = 1;
		for(j = 0; j < strlen(quto); j++)  //检测商是否为0，若为0则表示转换完毕，结束循环  
		{      
			if(quto[j] != '0') 
					ok = 0;
		}
		str2[top++] = int_2_char(last);
		 for(s = 0; s < strlen(quto); s++)  
		 {       if(quto[s] != '0') break;}
		 for(i = s; i < strlen(quto); i++)  //将本次除法运算的商作为新的被除数  
		 {       str1[i-s] = quto[i];  }
          str1[i-s] = '\0';  
	}
	for(int i = top-1; i >= 0; i--)  //逐位逆推得转换后的新数  
            printf("%c", str2[i]);  
        printf("\n\n");
	return 0;
}