#include<iostream>
#include<string>
using namespace std;
int getsum(string a)
{
	int sum = 0;
	int length = a.length();
	for (int i = 0; i < length; i++)
		sum += a[i] - '0';
	return sum;
}
int getFriendNum(int num) {
	int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main()
{
	int N;
	scanf("%d", &N);
	bool b[40] = { false };
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin>>temp;
		b[getsum(temp)] = true;
	}
	int times = 0;
	for (int i = 0; i < 40; i++)
		if (b[i] == true)
			times++;
	printf("%d\n", times);
	int tag = 0;
	for (int i = 0; i < 40; i++)
	{
		if (b[i] == true)
		{
			if (tag == 0)
			{
				printf("%d", i);
				tag = 1;
			}
			else
				printf(" %d", i);
		}
	}
	return 0;
}
/*
���ۣ���ȡ���ָ�λ��ӵķ������������굽����ת��)��Ҳ����set�����������飬�������Ǵ�С���󣬲��ظ�
*/