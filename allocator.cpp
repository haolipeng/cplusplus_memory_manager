//
// Created by Administrator on 2020\1\21 0021.
//
#include "allocator.h"
#include <cstdlib>

using namespace Common;
const int allocator::CHUNK = 5;

allocator::allocator() {
    freeStore = nullptr;
}

allocator::~allocator() {

}

void* allocator::allocate(size_t size) {
    struct obj* p = nullptr;

    if(!freeStore)
    {
        size_t chunk_size = CHUNK * size;
        freeStore = p = (obj*)malloc(chunk_size);

        //element 0 ~ (element -1)
        for (int i = 0; i < CHUNK - 1; ++i) {
            p->next = (obj*)((char*)p + size);
            p = p->next;
        }
        //last element
        p->next = nullptr;
    }

    p = freeStore;
    freeStore = freeStore->next;

    return p;
}

void allocator::deallocate(void *ptr, size_t size) {
    //将回收的object重新插回free list前端
    (static_cast<obj*>(ptr))->next = freeStore;
    freeStore = static_cast<obj*>(ptr);
}
