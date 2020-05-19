#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>fre;//������¼����Ԫ�س��ֵĴ���
typedef struct FreNode* Frequence;
struct FreNode {
	int fre;
	int name;
};
struct cmp {
	bool operator()(Frequence a, Frequence b)
	{
		if (a->fre == b->fre)
			return a->name > b->name;
		else
			return a->fre < b->fre;
	}
};
void Printmax(int K)//���fre������K��
{
	priority_queue<Frequence,vector<Frequence>,cmp>F;
	for (int i = 1; i < fre.size(); i++)
	{//��Ƶ����item����󶥶�
		if (fre[i] != 0)
		{
			Frequence Temp = (Frequence)malloc(sizeof(struct FreNode));
			Temp->fre = fre[i];
			Temp->name = i;
			F.push(Temp);
		}
	}
	for (int i = 0; i < K; i++)//���ǰK��Ƶ�ʲ�Ϊ0��
	{
		if (!F.empty())
		{
			Frequence Top = F.top();
			F.pop();
			if (Top->fre)
				printf(" %d", Top->name);
		}
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