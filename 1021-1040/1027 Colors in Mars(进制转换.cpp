/*
15 43 71
Sample Output:
#123456
*/
#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void Print(int n)
{
	if (n < 10)
		printf("%d", n);
	else
	{
		switch (n)
		{
			case 10:printf("A"); break;
			case 11:printf("B"); break;
			case 12:printf("C"); break;
		}
	}
	return;
}
int main()//ʮ����ת��Ϊʮ������
{
	int sum;
	int j = 3;
	printf("#");
	int b[2];
	int i = 0;
	while (j--)
	{
		cin >> sum;
		b[0] = sum / 13;
		b[1] = sum % 13;
		Print(b[0]);
		Print(b[1]);
	}
	return 0;
}
//�Աȿɵã��Ժ�������߽���ת��������ʹ���ַ����飨��Ҫ��һλ�ռ䣬\0��β��
#include <cstdio> 
using namespace std;
int main()
{
	char c[14] = { "0123456789ABC" };
	printf("#");
	for (int i = 0; i < 3; i++)
	{
		int num; scanf("%d", &num);
		printf("%c%c", c[num / 13], c[num % 13]);
	}
	return 0;
}