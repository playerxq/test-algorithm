// test-one.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	double operand1, operand2, addi;
	operand1 = atoi(argv[1]);
	operand2 = atoi(argv[2]);
	addi = operand1 + operand2;
	cout<<"/nfirst"<<operand1<<endl;
	cout<<"/nsecod"<<operand2<<endl;
	cout<<addi<<endl;
	system("pause");
}

