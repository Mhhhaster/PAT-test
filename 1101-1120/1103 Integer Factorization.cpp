#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;//��N�����ֽ��K������p�η�
vector<int> v, ans, tempAns;
void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}//v:0,1,4,9.....
void dfs(int index, int tempSum, int tempK, int facSum) {//��ֱ�۵Ľⷨ����K�������������������һ�Σ���¼�ܺͣ������Ⱦʹ洢��
    if (tempK == k) {//
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    for (; index >= 1;index--) {//indexΪ�������һ�������������ʼ�ݼ�
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;//index����Ϊ0
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();
    tempAns.resize(k);//��ʼ��tempAns�ĳ��ȣ���Ϊ������push��ֻ�ܸı�ֵ
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}