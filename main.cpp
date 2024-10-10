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

string input; // 输入的正规式

FA nfa,dfa,midfa; // 自动机

int main()
{
    // test00();
    cin>>input;
    re2nfa(input,&nfa); // Regular Expression -> NFA
    nfa2dfa(&nfa,&dfa); // NFA -> DFA
    mini_dfa(&dfa,&midfa); // DFA MINIMIZE
    dfa2code(&midfa); // DFA -> CODE (OUTPUT)
    return 0;
}
