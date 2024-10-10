#include <iostream>
using namespace std;

#include "tools.h"

void Transfer::printT()
{
    cout<<A<<"-"<<input<<"->"<<B<<" ";
}

void Status::insertT(string input,string B)
{
    Transfer *t = new Transfer;
    t->A = name;
    t->input = input;
    t->B = B;
    trans.push_back(t);
}

void Status::printS()
{
    cout<<name<<" ";
    for(Transfer *t:trans)
    {
        t->printT(); // 末尾有空格
    }
    cout<<endl;
}

void Status::setName(string name)
{
    this->name = name;
}

void FA::init()
{
    // 读取输入的FA表示字符串，代码未实现
}

void FA::insertS(Status *s)
{
    statuset.push_back(s);
}

void FA::printFA()
{
    for(Status *s:statuset)
        s->printS();
}