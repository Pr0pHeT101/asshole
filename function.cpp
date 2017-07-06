#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdio>

using namespace std;

typedef char ElementType;

void level_order(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *node = NULL;
    q.push(root);
    while (q.empty() != true)
    {
        node = q.front();
        q.pop();
        cout << node->data << " " << endl;
        if (NULL != node->left)
        {
            q.push(node->left);
        }
        if (NULL != node->right)
        {
            q.push(node->right);
        }
    }
}

//get random number function
vector<char> random_number()
{
    vector<char> number = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    srand((unsigned)time(NULL)); //初始化随机数种子
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

struct TreeNode
{
    ElementType data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createTree()
{
    char c;
    TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
    scanf("%c", &c);
    if (' ' == c)
    {
        T = NULL;
    }
    else
    {
        T = (TreeNode *)malloc(sizeof(TreeNode));
        T->data = c;
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}

void pre_order(TreeNode *root)
{
    if (root != NULL)
    {
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
        cout << root->data << " ";
        in_order(root->right);
    }
}

void post_order(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        post_order(root->left);
        post_order(root->right);
    }
}

int main()
{
    TreeNode *T;
    vector<char> number = random_number2();
    for (auto e : number)
    {
        cout << e;
    }
    // cout << "\ninput: " << endl;
    T = createTree();
    cout << "前序遍历： " << endl;
    pre_order(T);
    cout << "\n中序遍历： " << endl;
    in_order(T);
    cout << "\n后序遍历： " << endl;
    post_order(T);
    cout << endl;
    return 0;
}