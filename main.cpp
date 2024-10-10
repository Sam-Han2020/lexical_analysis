/*
MAIN PROGRAM
*/

#include <iostream>
using namespace std;

#include "tools.h"

void test00(FA *fa)
{
    // 测试代码
    // FA *nfa = new FA;
    fa->init("testfile.txt"); // 可以用读取文件的方式，初始化FA
    fa->printFA();
}

string input;

FA nfa,dfa,midfa;

int main()
{
    // test00(&nfa);
    cin>>input;
    re2nfa(input,&nfa); // Regular Expression -> NFA
    nfa2dfa(&nfa,&dfa); // NFA -> DFA
    mini_dfa(&dfa,&midfa); // DFA MINIMIZE
    dfa2code(&midfa); // DFA -> CODE (OUTPUT)
    return 0;
}