#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
    int n, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());//����
    while (e < n && a[e] > e + 1) e++;//e����������a[e]�������ݼ����ﳵ����ҪС���ﳵ������
    printf("%d", e);
    return 0;
}
/*10
6 7 6 9 3 10 8 2 7 8*/
//�������E��֤��������E������E��������i-1�����ȵ�i����С��