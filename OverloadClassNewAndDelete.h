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

    //virtual function的话会导致类的内存大小变化
    ~OverloadClassNewAndDelete()              { cout << "dtor. this="  << this << " id=" << _id << endl;  }
public:
    //////////////////////////new函数/////////////////////////////////////////
    static void* operator new(size_t size);//1

    /////////////////////////placement new各种形式,查看起调用形式//////////////////////////////
    //标准库提供的 placement new() 的重载
    void* operator new(size_t size, void* start)//2
    {
        cout << "operator new(size_t size, void* start), size= " << size << "  start= " << start << endl;
        return start;
    }

    void* operator new(size_t size, long extra)//3
    {
        cout << "operator new(size_t size, long extra)  " << size << ' ' << extra << endl;
        return malloc(size+extra);
    }

    void* operator new(size_t size, long extra, char init) //4
    {
        cout << "operator new(size_t size, long extra, char init)  " << size << ' ' << extra << ' ' << init << endl;
        return malloc(size+extra);
    }

    //array new
    static void* operator new[](size_t size);           //array new

    //////////////////////////delete函数/////////////////////////////////////////
    //一下是搭配上述placement new的各种called placement delete
    //当ctor发出异常，对应的operator (placement) delete就会被调用
    //负责释放其搭档兄弟(placement new)分配所得的memory
    static void  operator delete(void* deadObject);
    static void  operator delete(void* deadObject, size_t size);

    static void  operator delete[](void* deadObject);
    static void  operator delete[](void* deadObject, size_t size);
    static void  operator delete(void* deadObject, void* start);
    static void  operator delete(void* deadObject, long extra);
    static void  operator delete(void* deadObject, long extra, char a);
};


#endif //CPLUSPLUS_MEMORY_MANAGER_OVERLOADCLASSNEWANDDELETE_H
