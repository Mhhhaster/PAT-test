#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>fre;//������¼����Ԫ�س��ֵĴ���
vector<int>temp;
int Getmax()//���������fre����Ԫ��
{
	int max = 0;
	int position;
	for (int i = 1; i < temp.size(); i++)
		if (temp[i] > max)
		{
			max = temp[i]; position = i;
		}
	if (max)
	{
		temp[position] = 0;
		return position;
	}
	else
		return 0;
}
void Printmax(int K)//���fre������K��
{
	temp.resize(fre.size());
	for (int i = 1; i < fre.size(); i++)
		temp[i] = fre[i];//ȫ�����Ƶ���ʱ������
	while (K--)
	{
		int max = Getmax();
		if(max)
		printf(" %d", max);
	}
	printf("\n");
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	fre.resize(N + 1);
	int temp;
	scanf("%d" ,& temp);
	fre[temp]++;//fre[3]=1;
	for (int i = 1; i < N; i++)//ѭ��N-1��
	{
		scanf("%d", &temp);
		printf("%d:", temp);
		Printmax(K);//���fre������K��
		fre[temp]++;
	}
	return 0;
}