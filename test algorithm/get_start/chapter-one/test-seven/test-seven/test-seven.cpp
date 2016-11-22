// test-seven.cpp : �������̨Ӧ�ó������ڵ㡣
//

// poj-����ת����ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h>  
char str1[500], str2[500], quto[500];  //str1�������룬str2���������quto������  
int char_2_int(char c){  //�ַ�ӳ�䵽����  
    int n;  
    if(c >= '0' && c <= '9') n = c-'0';  
    else if(c >= 'A' && c <= 'Z') n = c-'A'+10;  
    else n = c-'a'+36;  
    return n;  
}  
char int_2_char(int n){  //����ӳ�䵽�ַ�  
    char c;  
    if(n >= 0 && n <= 9) c = n+'0';  
    else if(n >= 10 && n <= 35) c = n+'A'-10;  
    else c = n+'a'-36;  
    return c;  
}  
/*
int main(){  
    int b1, b2, n, s, cur, last, top;  //b1Ϊת��ǰ���ƣ�b2Ϊת�������  
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
			//��b1����ת��Ϊb2���Ƶķ���Ϊ����ȡ���ѭ������Ϊ0 ����ʱ�򱻳�����ֵ��ҪΪ10����
            for(i = 0; i < strlen(str1); i++){  //һ������ȡ�ࣨ�ؼ��� str1��b2������������ �ٽ�������������b2����ȡ��  ֱ����Ϊ0 
				//curΪ��ǰ�õ���10������ lastΪ�ϴ�i-1λ�õ�������
                cur = last*b1+char_2_int(str1[i]);  //���������Ӹ�λ��ʼ������λ��Ȩ�ۼӣ�����cur  
                if(cur < b2){  //��cur��ֵС�ڻ�b2��������ۼӣ��Ҽ��̵Ķ�ӦλΪ0  
                    last = cur;  
                    quto[i] = '0';  
                    continue;  
                }  
                else{  //��cur��ֵ���ڻ�b2������г������㣬�����̵Ķ�Ӧλ���������������Ȩ�ۼ���  
                    quto[i] = int_2_char(cur/b2);  
                    last = cur%b2;  
                }  
            }  
			//quto[]Ϊ�� 
            quto[i] = '\0';  
            quit = 1;  
            for(j = 0; j < strlen(quto); j++)  //������Ƿ�Ϊ0����Ϊ0���ʾת����ϣ�����ѭ��  
                if(quto[j] != '0') quit = 0;  
			//��������str2[]��  �����Ҫ�������
            str2[top++] = int_2_char(last);  //
			//��quto[]����Ϊ�µı����� ���˸�λ0
            for(s = 0; s < strlen(quto); s++)  
                if(quto[s] != '0') break;  
            for(i = s; i < strlen(quto); i++)  //�����γ������������Ϊ�µı�����  
                str1[i-s] = quto[i];  
            str1[i-s] = '\0';  
        }  
        for(int i = top-1; i >= 0; i--)  //��λ���Ƶ�ת���������  
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
		for(j = 0; j < strlen(quto); j++)  //������Ƿ�Ϊ0����Ϊ0���ʾת����ϣ�����ѭ��  
		{      
			if(quto[j] != '0') 
					ok = 0;
		}
		str2[top++] = int_2_char(last);
		 for(s = 0; s < strlen(quto); s++)  
		 {       if(quto[s] != '0') break;}
		 for(i = s; i < strlen(quto); i++)  //�����γ������������Ϊ�µı�����  
		 {       str1[i-s] = quto[i];  }
          str1[i-s] = '\0';  
	}
	for(int i = top-1; i >= 0; i--)  //��λ���Ƶ�ת���������  
            printf("%c", str2[i]);  
        printf("\n\n");
	return 0;
}