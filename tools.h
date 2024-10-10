/*
INTERFACE
*/

#pragma once

#include <iostream>
using namespace std;

#include <vector>

// 产生式类
class Transfer
{
public:
    string A; // A状态
    string input; // 输入input
    string B; // 转化为B状态
    void printT(); // 输出产生式
};

// 状态类，表示一个状态和它的产生式，作为FA的一行
class Status
{
    string name; // 状态名
    vector<Transfer*> trans; // 产生式的集合
public:
    void setName(string name); // 定义产生式名
    void insertT(string input,string B); // 插入产生式
    void printS(); // 输出状态和它的产生式在一行
};

// FA类
class FA
{
    vector<Status*> statuset; // 状态集合
public:
    void init(string filename); // 初始化，从文字读取FA
    void insertS(Status* s); // 插入一个状态
    void printFA(); // 把FA按照文字格式输出
};



// Regular Expression -> NFA
void re2dfa(string re,FA *nfa); // re接受输入的正规式，将生成的结果赋值给nfa

// NFA -> DFA
void nfa2dfa(FA *nfa,FA *dfa);

// DFA MINIMIZE
void minidfa(FA *dfa,FA *minidfa);

// DFA -> CODE
void dfa2code(FA *dfa); // 代码直接打印出来
