#include <stdio.h>
#include <iostream>

using namespace std;

void menu();
void sub_menu();


int main() {
    cout << "\t*************************************\n\n\t\t********欢迎********\n\n\t*************************************" << endl;
    getchar();
    menu();
    return 0;
}


void menu(){
    system("clear");
    char choice;
    cout << "\t*************************************\n\n\t\t1、随机生成树 （3层）\n\n\t\t2、层序输入自定义树 （3层）\n\n\t*************************************" << endl;
    cin >> choice;
    switch (choice)
    {
        case '1':
            sub_menu();
            break;
        case '2':
            sub_menu();
            break;
        default:cout << "\t\t请正确选择!\n";
            menu();
    }
}
void sub_menu()
{
    char choice;
    system("clear");
    cout << "\t*************************************\n\n\t\t1、先序遍历二叉树\n\n\t\t2、中序遍历二叉树\n\n\t\t3、后序遍历二叉树\n\n\t\t4、层序遍历二叉树\n\n\t*************************************" << endl;
    cin >> choice;
    
}
