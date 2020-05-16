/*5
88 70 61 63 65
Sample Output 1:
70 63 88 61 65
YES*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
	Tree Left;
	Tree Right;
	int value;
	int height;//��ָ��߶�Ϊ0
};
Tree Insert(Tree Root, int n);
Tree BuildTree();
void Traversal(Tree Root);//���������ͬʱ�ж��Ƿ�Ϊ��ȫ������
bool flag = true;
int main()
{
	Tree Root=BuildTree();//����һ��ƽ�������
	Traversal(Root);//ָʾ�Ƿ�Ϊ��ȫ������
	if (flag)
		printf("\nYES");
	else
		printf("\nNO");
	return 0;
}
Tree BuildTree()
{
	int TreeNodenum,tempnode;
	scanf("%d", &TreeNodenum);
	Tree Root = (Tree)malloc(sizeof(struct TreeNode));
	scanf("%d", &tempnode);
	Root->value = tempnode;
	Root->height = 0;
	Root->Left = NULL;
	Root->Right = NULL;
	while (--TreeNodenum)
	{
		scanf("%d", &tempnode);
		Root = Insert(Root, tempnode);
	}
	return Root;
}

int Getheight(Tree T)//NULLû��height��������Ҫдһ�����������б�
{
	if (!T)
		return -1;
	else
		return T->height;
}
Tree SingleLeftRotation(Tree T)//����Ҫ��������
{//!!!!!!ע�⣬Ҫ�ȸ���������������ܸ�������ĸ��׽ڵ�ĸ߶�
	Tree A = T->Left;
	T->Left = A->Right;
	A->Right = T;
	T->height= Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	A->height= Getheight(A->Left) > Getheight(A->Right) ? Getheight(A->Left) + 1 : Getheight(A->Right) + 1;
	return A;
}
Tree SingleRightRotation(Tree T)
{
	Tree A = T->Right;
	T->Right = A->Left;
	A->Left = T;
	T->height = Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	A->height = Getheight(A->Left) > Getheight(A->Right) ? Getheight(A->Left) + 1 : Getheight(A->Right) + 1;
	return A;//���ص�ǰ�ĸ��ڵ�A
}
Tree DoubleLeftRightRotation(Tree T)//������ת=���������������ڵ�����
{
	T->Left = SingleRightRotation(T->Left);//ע�⣬�߶Ȳ�û�иı䣬����Ҫ����
	return SingleLeftRotation(T);
}
Tree DoubleRightLeftRotation(Tree T)
{
	T->Right = SingleLeftRotation(T->Right);
	return SingleRightRotation(T);
}
Tree Insert(Tree T, int n)//��ָ�룿����or���ߣ���������
{
	if (!T)//��NULLָ�������������������Ҫ�ֱ����������ߵ�������б�
	{
		T = (Tree)malloc(sizeof(struct TreeNode));
		T->value = n;
		T->height = 0;
		T->Left = NULL;
		T->Right = NULL;
	}
	else if (n > T->value)//����
	{
		T->Right = Insert(T->Right, n);
		if (Getheight(T->Right) - Getheight(T->Left) == 2)
		{
			if (n > T->Right->value)//����������������
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	else if (n < T->value)
	{
		T->Left = Insert(T->Left, n);
		if (Getheight(T->Left) - Getheight(T->Right) == 2)
		{
			if (n > T->Left->value)//��������������
				T = DoubleLeftRightRotation(T);
			else
				T = SingleLeftRotation(T);
		}
	}
	T->height = Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	return T;
}
int tag = 0;
int p = 0;
void Traversal(Tree Root)//������������������������Ƿ�Ϊ��ȫ������
{//��ȫ�����������������һ���ڵ�ȱ��������ô������������Ľڵ㶼����������
	queue<Tree>Q;
	Q.push(Root);
	while (!Q.empty())
	{
		Tree T = Q.front();
		if (T->Right && !T->Left)
			flag = false;
		if (p == 0)
		{
			printf("%d", T->value); p++;
		}
		else
			printf(" %d", T->value);
		Q.pop();
		if (T->Left)Q.push(T->Left);
		if (T->Right)Q.push(T->Right);
		if (tag == 1 && (T->Left || T->Right))
			flag = false;
		if (!T->Left || !T->Right)//�������������������Ϊ��
			tag = 1;
	}
}
/*��Ϊ��ϰƽ��������ǳ���
1.NULL�ڵ�Ϊ0����ֵ�ڵ�>=1��
2.buildtree������newnode��n-1��insert
3.insertע���ڿ�ͷ�ж�NULL��������ǵø������ߡ�
4.����ע��������ߴ�������
5.����=���������������ڵ�����
6.���е�insert��Ҫ����ֵ������ֵ���ǵ�ǰ�ݹ�ĸ��ڵ�
*/
