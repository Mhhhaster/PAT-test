#include<iostream>
#include<stdlib.h>
using namespace std;
//������ʾ�������ĿҪ���ҵ���С��i��k����Ҫ��i��k���������ʼ����
//���������ѵ����������������Ӧ������������������������򵥺ܶ�
//�ȽϿӵĵ��ǣ�˵��ģ����ʵ������˼����һ����һ��������
int main()
{
	int a[101];
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		scanf_s("%d", &a[i]);
	for(int i=1;i<N;i++)
		for (int j = i+1; j <= N; j++)//�������е��������
		{//���ڵ�i�ź͵�j��������,�������Ǻ���
			int liarnum = 0;
			int tag = 0;//0����û����������
			for (int k = 1; k <= N; k++)
			{
				if (a[k] > 0)//��k����˵����
				{
					if (a[k] == i || a[k] == j)//��˵�ĺ���������
					{
						liarnum++;
						if (k == i || k == j)
							tag++;
					}
				}
				if (a[k] < 0)//��k����������
				{
					if (-a[k] != i &&-a[k] != j)//�ҵ��������Ǵ��
						liarnum++;
					if (k == i || k == j)
						tag++;
				}
			}
			if (liarnum == 2&&tag==1)//δ�ж��Ƿ�����������
			{
				printf("%d %d", i, j);
				return 0;
			}
		}
	printf("No Solution");
	return 0;
}