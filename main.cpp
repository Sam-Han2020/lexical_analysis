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
    Status *s = new Status;
    s->setName("A");
    s->insertT("f","B");
    nfa.insertS(s);
    nfa.printFA();
}

int main()
{
    test00();
    return 0;
}