#include "perClassAllocatorBetter.h"

//
// Created by Administrator on 2020\1\21 0021.
//
#include "perClassAllocatorBetter.h"

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;
void *Airplane::operator new(size_t size) {
    if(size != sizeof(Airplane))
    {
        return ::operator new(size);
    }

    Airplane* p = headOfFreeList;

    //如p有效，就把list头部移动到下一个元素
    if(p)
    {
        headOfFreeList = headOfFreeList->next;
    }
    else
    {
        //一次性申请BLOCK_SIZE个内存
        Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));

        //组成一个新freelist，将多个小块串联起来，但跳过0元素，因为需要传递给调用者
        for (int i = 1; i < BLOCK_SIZE - 1; ++i) {
            newBlock[i].next = &newBlock[i+1];
        }
        //最后一个元素直接赋值为0
        newBlock[BLOCK_SIZE - 1].next = 0;

        //将p设置为头部
        p = &newBlock[0];
        headOfFreeList = &newBlock[1];
    }

    return p;
}

void Airplane::operator delete(void *deadObject,size_t size) {
    if(nullptr == deadObject)
        return;

    if(size != sizeof(Airplane))
    {
        ::operator delete(deadObject);
        return;
    }

    Airplane* tmp = static_cast<Airplane*>(deadObject);
    tmp->next = headOfFreeList;
    headOfFreeList = tmp;
}