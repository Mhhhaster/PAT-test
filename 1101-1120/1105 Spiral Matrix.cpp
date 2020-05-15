#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	scanf("%d", &N);
	vector<int>a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end(), cmp);//sort����������vector��begin��end��Ϊ����
	int m,n;
	for (n = sqrt((double)N); n >= 1; n--) {
		if (N % n == 0) {
			m = N / n;
			break;
		}
	}
	//����һ��m*n����
	vector<vector<int>>b(m, vector<int>(n));//���׵�����b��Ȼ��Զ��׷ֱ𸳳���
	//һȦΪһ��ѭ����4*3Ϊ2Ȧ��m*nһ����Ҫ��m+1/2Ȧ
	int times = (m + 1) / 2;
	int row = 0, col = 0;//��(0,0)��ʼ
	int j = 0;//j��a����ļ�����
	for (int i = 1; i <= times; i++)//ÿһȦ�����Ҹ�ֵm-2*times+1,����n-2*times����������
	{
		if(j<=N-1)
		b[row][col] = a[j];
		for (int k = 1; k <=n- 2 * i + 1&&j<=N-1; k++)
			b[row][col++] = a[j++];
		for (int k = 1; k <= m - 2 * i + 1 && j <= N - 1; k++)
			b[row++][col] = a[j++];
		for (int k = 1; k <= n - 2 * i + 1 && j <= N - 1; k++)
			b[row][col--] = a[j++];
		for (int k = 1; k <= m - 2 * i + 1 && j <= N - 1; k++)
			b[row--][col] = a[j++];
		row++; col++;//�����ƶ�һȦ
	}
	for (int r = 0; r < m; r++)
	{
		for (int q = 0; q < n; q++)
		{
			printf("%d", b[r][q]);
			if (q != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
//��������Ҫ����Ū��ѭ��Ƕ�ף�ģ����������