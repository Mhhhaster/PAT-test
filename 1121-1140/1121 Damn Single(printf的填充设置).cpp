//��0������99999���������˳��ֹ����Ҷ���û�г��ֹ�����ô���
#include<iostream>
#include<string>
using namespace std;
struct PeoNode {
	int cp=-1;
	bool pre = false;//Ĭ��û��cp
}peo[100000];
int main()
{
	int N;
	scanf("%d", &N);
	int cp1, cp2;
	while (N--)
	{
		scanf("%d%d", &cp1, &cp2);
		peo[cp1].cp = cp2;
		peo[cp2].cp = cp1;
	}
	int M;
	scanf("%d", &M);
	int man;
	while (M--)
	{
		scanf("%d", &man);
		peo[man].pre = true;
	}
	int single = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (peo[i].pre == true)//���ȸ��˵ó�ϯ
		{
			if (peo[i].cp == -1)
				single++;
			else if (peo[peo[i].cp].pre == false)//ҪôûCPҪôCPû��ϯ
				single++;
		}
	}
	printf("%d\n", single);
	int tag = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (peo[i].pre == true)//���ȸ��˵ó�ϯ
		{
			if (peo[i].cp == -1 || (peo[i].cp != -1) && (peo[peo[i].cp].pre == false))//��ʵͬ��
			{
				if (tag == 0)
				{
					printf("%05d", i);
					tag++;
				}
				else
					printf(" %05d", i);
			}
		}
	}
}
/*
���ۣ�һ��Ҫ��֪printf����䷽����Ҳ����set�����������飬�������Ǵ�С���󣬲��ظ�
*/