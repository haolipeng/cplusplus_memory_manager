//
// Created by Administrator on 2020\1\20 0020.
//

#include "perClassAllocator.h"

//静态变量初始化
perClassAllocator* perClassAllocator::freeStore = NULL;
const int perClassAllocator::screenChunk = 24;

//申请的对象长度是定长的
void *perClassAllocator::operator new(size_t size) {
    perClassAllocator* p = nullptr;//保存链表头指针

    //link list 是空的，申请一大块内存，使用链表串联起来
    if(nullptr == freeStore)
    {
        //一次性申请screenChunk数量，可能会内存使用效率低
        size_t  chunk = screenChunk * size;
        freeStore = p = reinterpret_cast<perClassAllocator*>(new char[chunk]);

        //将大块内存切割成N个小块内存，用单向链表linked list串联起来
        for (; p != &freeStore[screenChunk - 1] ; ++p) {
            p->next = p + 1;
        }

        p->next = nullptr;
    }
    //从内存块链表中获取符合要求的内存块
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void perClassAllocator::operator delete(void *ptr, size_t size) {
    //将回收的object重新插回free list前端
    (static_cast<perClassAllocator*>(ptr))->next = freeStore;
    freeStore = static_cast<perClassAllocator*>(ptr);
}
