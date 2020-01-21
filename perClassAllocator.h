//
// Created by Administrator on 2020\1\20 0020.
//
// 抄袭C++ primer的代码
#ifndef NEW_DELETE_STUDY_PERCLASSALLOCATOR_H
#define NEW_DELETE_STUDY_PERCLASSALLOCATOR_H

#include <cstddef>
#include <iostream>
using  namespace std;

//可减少动态申请内存中的cookie内容的大小
class perClassAllocator {
public:
    perClassAllocator()
    {
        i = 0;
        next = nullptr;
    }
    ~perClassAllocator()
    {
        i = 0;
        next = nullptr;
    }

    int get() {return i;}

    explicit perClassAllocator(int x):i(x) { next = nullptr; };//善于使用explicit???
public:
    static void* operator new(size_t size);
    static void operator delete(void* ptr, size_t size);
private:
    perClassAllocator* next;        //指向下一个内存节点的指针，此处多用一个指针浪费了内存，可以优化，
    static  perClassAllocator* freeStore;   //可申请内存的链表位置（不断变化）
    static  const int screenChunk;
private:
    int i;  //data member
};

#endif //NEW_DELETE_STUDY_PERCLASSALLOCATOR_H
