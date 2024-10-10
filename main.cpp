/*
MAIN PROGRAM
*/

#include <iostream>
using namespace std;

#include "tools.h"

void test00()
{
    // 测试代码
    FA nfa;
    nfa.init("testfile.txt"); // 可以用读取文件的方式，初始化FA
    nfa.printFA();
}

int main()
{
    test00();
    return 0;
}