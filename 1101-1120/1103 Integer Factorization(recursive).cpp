#include<iostream>
#include<vector>
using namespace std;
void solve(int N, int P, int K, int sum, int level);
int maxsum = 0;
vector<int>a;
vector<int>b;
double times = 0;
int main()//�ݹ���
{
    int N, P, K;
    scanf("%d%d%d", &N, &P, &K);//����N�ֽ�ΪP��K�η�����֮��
    a.resize(P);//Ϊa��b�����С
    b.resize(P);//bΪ�������
    solve(N, P, K, 0, 0);
    if (maxsum == 0)
        printf("Impossible");
    else
    {
        printf("%d = ", N); //169 = 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 5 ^ 2
        printf("%d^%d", b[0], K);
        for (int i = 1; i < P; i++)
            printf(" + %d^%d", b[i], K);
    }
    printf("\n%lf\n", times);
    return 0;
}
int pow(int a, int b)
{
    while (--b)
        a *= a;
    return a;
}
void solve(int N, int P, int K, int sum, int level)//����N�ֽ�ΪP��K�η�����֮��,sumΪ��ǰ�ĺ�,level��¼����
{//�ݹ���ֹ������P=1;N<=0;P>N
    times++;
    if (N <= 0)
        return;
    int i;
    for (i = 1;; i++)
        if (pow(i, K) > N)//�ҵ�����factor,169�����factorΪ13��168Ϊ14
            break;
    if (P == 1)//����N�ֽ�Ϊ1����
    {
        if (pow(i - 1, K) == N)//�ֽ�ɹ�����ֹ����
        {
            if (i - 1 + sum > maxsum)
            {
                maxsum = i - 1 + sum;//������Сfactor��
                for (int k = 0; k < level; k++)
                {
                    b[k] = a[k];
                }
                b[level] = i - 1;
            }
        }
        return;
    }
    int j;
    if (level)//ÿ����Ҫ����һ�����С�������
        j = i - 1 > a[level - 1] ? a[level - 1] : i - 1;
    else
        j = i - 1;
    for (; j >= 1; j--)
    {
        a[level] = j;//��level�����Ϊj
        if (N - pow(j, K) >= P - 1)
            solve(N - pow(j, K), P - 1, K, sum + j, level + 1);//�ݹ�Ϊ����N'�ֽ�ΪP-1��K�η�����֮��,�ɴ���С���������������
    }
}
/*K=2ʱ�ܵú���
���ۣ�������ʱ����ͽ�������˼·�ܺá�
���ַ�����1.����P����������N��K�η�����1����һ�飬������ѭ��
2.�ݹ�Ϊһ����С��ģ������
�ݹ�����Ѿ����˺ܶ൫������ʱ��
*/