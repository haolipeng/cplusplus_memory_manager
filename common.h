//
// Created by Administrator on 2020\1\21 0021.
//

#ifndef CPLUSPLUS_MEMORY_MANAGER_COMMON_H
#define CPLUSPLUS_MEMORY_MANAGER_COMMON_H
#include <iostream>
using namespace std;
class Complex
{
public:
    Complex()
    {
        cout<<"call ctor function:"<<this<<endl;
    }
    ~Complex()
    {
        cout<<"call dtor function:"<<this<<endl;
    }

    Complex(int first, int second)
    {
        cout<<"call ctor with paramter function:"<<this<<endl;
    }
};

//用于test_call_ctor_directly测试
class A
{
public:
    int id;

    A() : id(0)      { cout << "default ctor. this="  << this << " id=" << id << endl;  }
    explicit A(int i) : id(i) { cout << "ctor. this="  << this << " id=" << id << endl;  }
    ~A()             { cout << "dtor. this="  << this << " id=" << id << endl;  }
};

#endif //CPLUSPLUS_MEMORY_MANAGER_COMMON_H
