#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<bool>chosen;
vector<string>name;
int times = 0;//ÿ�����ǰ����һ��
int Choose(int i)//ѡ��name[i]Ϊ�齱�ˣ����chosen[i]=false,˵����ѡ���ˣ����Ϊtrue��������Ұ�chosen��Ԫ�ظ���
{
	if (chosen[i] == false)
		return Choose(i + 1);
	else
	{
		times++;
		cout << name[i] << endl;
		for (int j = 0; j < name.size(); j++)
			if (name[i] == name[j])
				chosen[j] = false;
	}
	return i;
}
int main()
{
	int M, N, S;
	scanf("%d%d%d", &M, &N, &S);
	name.resize(M);
	chosen.resize(M, true);
	for (int i = 0; i < M; i++)
		cin >> name[i];
	for (int i = S - 1; i < M; i += N)
	{
		int j = Choose(i);
		if (j > i)
			i = j;
	}
	if (times == 0)
		printf("Keep going...\n");
	return 0;
}