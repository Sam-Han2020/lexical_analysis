/*
INTERFACE
*/

#pragma once

#include <iostream>
using namespace std;

#include <vector>

class Transfer
{
public:
    string A;
    string input;
    string B;
    void printT();
};

class Status
{
    string name; // 状态名
    vector<Transfer*> trans;
public:
    void insertT(string input,string B);
    void printS();
    void setName(string name);
};

// fa类
class FA
{
    vector<Status*> statuset;
public:
    void init();
    void insertS(Status* s);
    void printFA();
};



// Regular Expression -> NFA
void re2dfa(string re,FA *nfa); // re接受输入的正规式，将生成的结果赋值给nfa

// NFA -> DFA
void nfa2dfa(FA *nfa,FA *dfa);

// DFA MINIMIZE
void minidfa(FA *dfa,FA *minidfa);

// DFA -> CODE
void dfa2code(FA *dfa); // 代码直接打印出来
