#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<double>a(N);
	vector<bool>b(N, true);
	double* c = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &a[i]);
		c[i] = a[i];
	}
	sort(c, c + N);
	int num = 0;//��ʾ������Ϊpivot������
	int max = 0;
	for (int i = 0; i < N; i++)
		if (a[i] != c[i] || a[i] < max)//λ����ͬ�Ǳ�Ҫ������λ����ͬ�Ҵ�����max�ǳ�Ҫ����(�����Ƴ�С����min)
		{
			b[i] = false; num++;
			if (a[i] > max)
				max = a[i];
		}
	printf("%d\n", N - num);
	int flag = 1;
	for (int i = 0; i < N; i++)
		if (b[i])
		{
			if (flag == 1)
			{
				printf("%d", int(a[i]));
				flag++;
			}
			else
				printf(" %d", int(a[i]));
		}
	printf("\n");
	return 0;
}
/*�������𲻴󣬲�ͬ�������ǽ������pivot�½�һ��������룬��������һ��boolָʾ��Щ�Ǵ����pivot
�����ڶ��е�printf("\n")˵�����û������Ļ�Ҫ�������һ������
*/