#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
bool compare(string a, string b)//�ж�ʱ��a�Ƿ��b��
{//xx:xx:xx
    if (a[0] == b[0] && a[1] == b[1])
    {
        if (a[3] == b[3] && a[4] == b[4])
            return (a[6] > b[6] || (a[6] == b[6] && a[7] > b[7]));
        else
            return (a[3] > b[3] || (a[3] == b[3] && a[4] > b[4]));
    }
    else
        return (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]));
}
int main()//����Ҳ�ɽ�ʱ��ת��Ϊ��
{
    int N;
    cin>>N;
    string open, close;//��¼��һ���˺����һ��������
    string t1 = "24:00:00";
    string t2 = "00:00:00";//��¼���������ʱ��
    string name, tempt1, tempt2;
    while (N--)
    {
        cin >> name >> tempt1 >> tempt2;
        if (compare(t1, tempt1))//t1����tempt1,close��Ҫ����
        {
            open = name;
            t1 = tempt1;
        }
        if (!compare(t2, tempt2))//t2����tempt2
        {
            close = name;
            t2 = tempt2;
        }
    }
    cout << open << " " << close;
}
/*3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40*/