#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0*/
int main()
{
	int N;
	double rawprice, incpercent;
	scanf("%d%lf%lf", &N, &rawprice, &incpercent);
	vector<int>a(N);//��¼�Լ����ϼ�
	vector<bool>b(N, false);//��¼�Ƿ����¼�
	int downnum, temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &downnum);
		if (downnum)//���¼�
		{
			while (downnum--)
			{
				scanf("%d", &temp);
				a[temp] = i;//�¼�ָ����
				b[i] = true;
			}
		}
	}
	int times, min = 100000, num=1;//��¼���������ҵ�����������Ҫ�Ĵ���
	for (int i = 0; i < N; i++)
		if (!b[i])	//b[i]=flase��Ϊû���¼ҵ�������
		{
			int j = a[i];
			times = 1;
			while (j != 0)
			{
				j = a[j];
				times++;
			}
			if (times < min)
			{
				min = times;
				num = 1;
			}
			else if (times == min)
				num++;
		}
	printf("%.4lf %d", rawprice *pow(1 + incpercent / 100, min), num);
	return 0;
}
//�ýⷨ��Ϊ����ֻ����һ���ϼң������ж���¼ң����Բ��ò��鼯�������ύ���ִ󲿷ֳ�������ֻ�ܻ��ֽⷨ��