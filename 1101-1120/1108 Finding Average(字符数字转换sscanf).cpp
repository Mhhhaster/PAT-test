#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool Judge(string input)//�����ж������Ƿ�Ϸ������Ϸ������
{
    char a[50], b[50];
    strcpy(a, input.c_str());
    double temp = -9999;
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f", temp);//��temp�ĳ�ֵ������b��ͬʱ��Ӱ����a��
    /*���ۣ�sscanf�Ĳ�����ֻ���������ַ���ֵ��ȥ������Ͳ���ֵ��temp��ֵ̫���������ٸ�ֵ��ʱ�������b�ķ�Χ��Ӱ�쵽��a*/
    /*��������temp��ֵһ���̵ĳ�ֵ*/
    int flag = 0;
    for (int j = 0; j < strlen(a); j++)
        if (a[j] != b[j])
            flag = 1;
    if (!flag && temp >= -1000 && temp <= 1000)
        return true;
    else
    {
        printf("ERROR: ");
        cout << input;
        printf(" is not a legal number\n");
        return false;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    string input;
    float sum = 0.00;
    int flag = 0;//����ָʾ������������
    while (N--)
    {
        cin >> input;
        if (Judge(input))
        {
            sum += stof(input);
            flag++;
        }
    }
    if (flag == 0)
        printf("The average of 0 numbers is Undefined");
    if (flag == 1)
        printf("The average of 1 number is %.2f", sum);
    if (flag > 1)
        printf("The average of %d numbers is %.2f", flag, sum / flag);
    return 0;
}