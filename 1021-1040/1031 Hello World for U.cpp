#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
/*
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
*/
int main()
{
	string str;
	cin >> str;
	int len = str.length();
	int len1 = (len-1) / 3;
	int len3 = len1;
	int len2 = len - len1 - len3;
	int i;
	//�����i��len2-2���ո�len-i��ѭ��len1��
	for (i = 0; i < len1; i++)
	{
		printf("%c", str[i]);
		for (int j = 1; j <= len2 - 2; j++)
			printf(" ");
		printf("%c\n", str[len - 1 - i]);
	}
	for (int j = i; j < len - len1; j++)
		printf("%c", str[j]);
	return 0;
}
//����ûʲô��˵�ģ���ѧ����