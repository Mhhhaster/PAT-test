#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int>a(N);
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    vector<int>result(max);
    for (int i = 1; i < max; i++)
    {
        int biggernum = 0;
        for (int j = 0; j < N; j++)
            if (a[j] > i)
                biggernum++;
        result[i] = biggernum;//result�洢����i������
    }
    int i;
    for (i = 1; i < max; i++)//result[i]��С��i�����ҵ����i��֤relust[i]>=i
        if (result[i] < i)//������������
            break;
    printf("%d", i-1);
}