#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
typedef char ElementType;
int i = 0;

struct TreeNode
{
	ElementType data;
	TreeNode *left;
	TreeNode *right;
};
TreeNode *T;

void menu();
void sub_menu();

vector<char> random_number()
{
	vector<char> number = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int index = 1 + rand() % 6;
		char tmp;
		tmp = number[index];
		number[index] = number[0];
		number[0] = tmp;
	}
	return number;
}

vector<char> random_number2()
{
	vector<char> number = random_number();
	vector<char> number_res;
	for (int i = 0, j = 0; i < 15; i++)
	{
		if (i == 3 || i == 4 || i == 6 || i == 7 || i == 10 || i == 11 || i == 13 || i == 14)
		{
			number_res.push_back(' ');
		}
		else
		{
			number_res.push_back(number[j]);
			j++;
		}
	}
	return number_res;
}

TreeNode *createTree(vector<char> number);
void pre_order(TreeNode *root);
void in_order(TreeNode *root);
void post_order(TreeNode *root);

void randtree()
{
	vector<char> number = random_number2();
//	for (auto e : number)
//	{
//		cout << e;
//	}
	T = createTree(number);
}

void inputtree()
{
	vector<char> number2;
	char c;
	getchar();
	for (int i = 0; i < 15; i++)
	{
		scanf("%c", &c);
		number2.push_back(c);
	}
	T = createTree(number2);
}

void menu()
{
	system("clear");
	char choice;
	cout << "\t*************************************\n\n\t\t1、随机生成树 （3层）\n\n\t\t2、先序输入自定义树 （3层）\n\n\t*************************************" << endl;
	cin >> choice;
	switch (choice)
	{
	case '1':
		randtree();
		sub_menu();
		break;
	case '2':
		inputtree();
		sub_menu();
		break;
	default:
		cout << "\t\t请正确选择!\n";
		menu();
	}
}
void sub_menu()
{
	char choice;
	system("clear");
	cout << "\t************************************ 1\n\t\t\t\t\t    / \\\n\t\t\t\t\t   2   9\n\t\t1、先序遍历二叉树\t  / \\ / \\\n\t\t\t\t\t 3  6 10 13\n\t\t2、中序遍历二叉树\n\n\t\t3、后序遍历二叉树\n\n\t*************************************" << endl;
	cin >> choice;
	switch (choice)
	{
	case '1':
		pre_order(T);
		sub_menu();
		break;
	case '2':
		in_order(T);
		sub_menu();
		break;
	case '3':
		post_order(T);
		sub_menu();
		break;
	}
}

TreeNode *createTree(vector<char> number)
{
	char c;
	TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
	if (' ' == number[i])
	{
		T = NULL;
		i++;
	}
	else
	{
		T = (TreeNode *)malloc(sizeof(TreeNode));
		T->data = number[i];
		i++;
		T->left = createTree(number);
		T->right = createTree(number);
	}
	return T;
}

void pre_order(TreeNode *root)
{
	if (root != NULL)
	{
		getchar();
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(TreeNode *root)
{
	if (root != NULL)
	{
		in_order(root->left);
		getchar();
		cout << root->data << " ";
		in_order(root->right);
	}
}

void post_order(TreeNode *root)
{
	if (root != NULL)
	{
		getchar();
		cout << root->data << " ";
		post_order(root->left);
		post_order(root->right);
	}
}
int main()
{
	cout << "\t*************************************\n\n\t\t********欢迎********\n\n\t*************************************" << endl;
	getchar();
	menu();
	return 0;
}
