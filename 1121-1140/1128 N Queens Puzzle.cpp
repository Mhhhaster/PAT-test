/*Sample Input:
4           
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
Sample Output:
YES
NO
NO
YES
ȷ��ÿ��ÿ�к�ÿб�߲���ͻ
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int K,N,temp;
	scanf("%d", &K);
	while (K--)
	{
		bool flag = true;
		scanf("%d", &N);
		vector<int>J(N);
		for (int i = 0; i < J.size(); i++)
			scanf("%d", &J[i]);
		for (int i = 0; i < J.size(); i++)//һ��Ԫ�ز��ܺ�����Ԫ�ضԽ��ߣ�Ҳ�������
		{
			for (int j = i+1; j < J.size(); j++)
			{
				if (J[i] == J[j] || J[i] - J[j] == j - i || J[i] - J[j] == i - j)
					flag = false;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}