#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int times, mindepth = 100000, num = 1;//��¼���������ҵ�����������Ҫ�Ĵ���
vector<int>a[100000];//����ʮ���vector���͵��������ɰ��±����
void DFS(int node,int depth)//��a[0]��ʼdfs,��¼��ǰ������ȣ���ȵ���СֵΪmin
{
	if (a[node].size() == 0)//���ʵĽڵ�Ϊ������
	{
		if (depth < mindepth)
		{
			mindepth = depth; num = 1;
		}
		else if (depth == mindepth)
			num++;
	}
	for (int i = 0; i < a[node].size(); i++)//dfs�ýڵ�������¼�
		DFS(a[node][i], depth + 1);
}
int main()
{
	int N;
	double rawprice, incpercent;
	scanf("%d%lf%lf", &N, &rawprice, &incpercent);
	
	int downnum, temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &downnum);//�����¼ҵ�����
		while (downnum--)
		{
			scanf("%d", &temp);
			a[i].push_back(temp);
		}
	}//ֱ���γ���һ�����Ʋ����еĶ�ά����ṹ
	DFS(0,0);
	printf("%.4lf %d", rawprice * pow(1 + incpercent / 100, mindepth), num);
	return 0;
}
//�����ջ���ѧ����ʹ��vector<int>a[maxsize]�Ľṹ���൱��һ����̬��ά����
//ѧ����DFS�ı�׼˼����ʽ��������˵������Ҫ������������ǰ���ʽڵ����ȡ�
//���⻹���Խ��м�֦�������ǰ����Ѿ�����mindepth����ʵ��û�����岻������

