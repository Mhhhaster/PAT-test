#include<iostream>
#include<vector>
#define Uplimit 1000
using namespace std;
vector<vector<int>>G;
int main()
{
	int vertexnum, edgenum;
	scanf("%d%d", &vertexnum, &edgenum);
	G.resize(vertexnum+1);//0��vertexnum��
	for (int i = 1; i <= vertexnum; i++)
		G[i].resize(vertexnum + 1,Uplimit);//��ÿһ�г�ʼ��0��vertexnum��
	int row, col;
	while (edgenum--)
	{
		scanf("%d%d", &row, &col);
		G[row][col] = 1;
		G[col][row] = 1;
	}
	int testnum,cyclenum;
	scanf("%d", &testnum);
	while (testnum--)
	{
		bool flag = true;//��־���Ƿ���������
		scanf("%d", &cyclenum);
		vector<int>cycle(cyclenum+1);
		vector<bool>pre(vertexnum+1,false);
		for (int i = 1; i <= cyclenum; i++)
		{
			scanf("%d", &cycle[i]);
			pre[cycle[i]] = true;//�Ƿ�����˵ı�־
		}
		//��Ҫ�����ĸ���������β��ȣ�N+1�����㣬·ͨ�����ж��㶼����
		if (cyclenum != vertexnum + 1)
			flag = false;
		else if (cycle[1] != cycle[cyclenum])
			flag = false;
		else
		{
			for (int i = 1; i <= vertexnum; i++)
				if (pre[i] == false)
					flag = false;
		}
		if (flag)//������ж�һ���Ƿ�·ͨ
		{
			int pathlength = 0;
			for (int i = 1; i < cyclenum; i++)
				pathlength += G[cycle[i]][cycle[i + 1]];
			if (pathlength > Uplimit)
				flag = false;
		}
		if (flag)printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
//ûʲô�Ѷȣ���ϰһ�¶�ά������ʹ�÷���