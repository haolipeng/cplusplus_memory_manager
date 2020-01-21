//
// Created by Administrator on 2020\1\21 0021.
//

#ifndef CPLUSPLUS_MEMORY_MANAGER_OVERLOADCLASSNEWANDDELETE_H
#define CPLUSPLUS_MEMORY_MANAGER_OVERLOADCLASSNEWANDDELETE_H

#include <string>
#include <iostream>
using namespace std;

class OverloadClassNewAndDelete {
public:
    int _id;
    long _data;
    std::string _str;
public:
    OverloadClassNewAndDelete() : _id(0)      { cout << "default ctor. this="  << this << " id=" << _id << endl;  }
    OverloadClassNewAndDelete(int i) : _id(i) { cout << "ctor. this="  << this << " id=" << _id << endl;  }
    //virtual
    ~OverloadClassNewAndDelete()              { cout << "dtor. this="  << this << " id=" << _id << endl;  }
public:
    static void* operator new(size_t size);
    static void* operator new[](size_t size);
    static void  operator delete(void* deadObject, size_t size);
    static void  operator delete[](void* deadObject, size_t size);
};


#endif //CPLUSPLUS_MEMORY_MANAGER_OVERLOADCLASSNEWANDDELETE_H
