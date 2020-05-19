#include<iostream>
#include<vector>
#define uplimit 10000
using namespace std;    
bool component = true;
vector<bool>visit;
vector<vector<int>>G;
void DFS(int index )//���±�Ϊ1�Ķ��㿪ʼ������ÿ�εݹ鵽i������û�з��ʹ����ڽӵ�
{
    visit[index] = true;
    for (int i = 1; i < visit.size(); i++)
        if (G[index][i] == 1&&visit[i]==false)
            DFS(i);
}
int main()
{
    int vertexnum, edgenum;
    scanf("%d%d", &vertexnum, &edgenum);
    G.resize(vertexnum + 1, vector<int>(vertexnum + 1,uplimit));
    int row, col;
    visit.resize(vertexnum + 1,false);
    while (edgenum--)
    {
        scanf("%d%d", &row, &col);
        G[row][col] = 1;
        G[col][row] = 1;
    }
    vector<int>D(vertexnum + 1,0);
    for (int i = 1; i <= vertexnum; i++)
    {
        for (int j = 1; j <= vertexnum; j++)
            if (G[i][j] == 1)//˵��i��j��·��
                D[i]++;
    }
    int oddnum = 0;
    for (int i = 1; i <= vertexnum; i++)
    {
        printf("%d", D[i]);
        if (D[i] % 2 == 1)
            oddnum++;
        if (i != vertexnum)
            printf(" ");
        /* if (D[i] == 0)
             component = false;
     ���ϳ���𰸲�ȫ�ԣ���Ϊͼ����ͨ�Բ���ֻƾ�Ƿ��нڵ�Ķ�Ϊ0�жϣ�������������֮�࣬Ҫ��dfs�ж���ͨ��*/
    }
    
    DFS(1);
    for (int i = 1; i <= vertexnum; i++)
        if (visit[i] == false)//ֻҪ��һ���ڵ�û�б����ʹ���˵��ͼ����ͨ
            component = false;
    if (oddnum == 0&&component==true)
        printf("\nEulerian");
    else if (oddnum == 2&&component==true)
        printf("\nSemi-Eulerian");
    else
        printf("\nNon-Eulerian");
    return 0;
}