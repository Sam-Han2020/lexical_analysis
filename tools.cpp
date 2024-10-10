#include <iostream>
using namespace std;

#include <fstream>  
#include <sstream>
#include <string>

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

void FA::init(string filename) // 可能到时候要根据系统的输入格式修改一下
{
    // 打开文件进行读取
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 读取输入的FA
    std::string line;

    // 逐行读取输入
    while (std::getline(file, line)) 
    {
        std::istringstream lineStream(line);
        std::string firstToken;
        Status *s = new Status;

        // 读取第一个token
        if (lineStream >> firstToken) 
        {
            s->setName(firstToken);
        }

        std::string word;
        // 读取其余的token
        while (lineStream >> word)
        {
            // 解析类似于 "0-a->1" 的token
            size_t dashPos = word.find('-');
            size_t arrowPos = word.find("->");

            if (dashPos != std::string::npos && arrowPos != std::string::npos && arrowPos > dashPos) 
            {
                // 提取字符a和目标状态1
                std::string symbol = word.substr(dashPos + 1, arrowPos - dashPos - 1);
                std::string targetState = word.substr(arrowPos + 2);
                s->insertT(symbol,targetState);
            }
        }
        insertS(s);
    }
    file.close();
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