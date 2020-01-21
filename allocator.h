//
// Created by Administrator on 2020\1\21 0021.
//

#ifndef CPLUSPLUS_MEMORY_MANAGER_ALLOCATOR_H
#define CPLUSPLUS_MEMORY_MANAGER_ALLOCATOR_H
#include <cstddef>
namespace Common
{
class allocator{
public:
    allocator();
    ~allocator();
public:
    void* allocate(size_t size);
    void deallocate(void* ptr, size_t size);
private:
    struct obj{
        struct obj* next;
    };

    obj* freeStore;
    static const int CHUNK;
};
}

#endif //CPLUSPLUS_MEMORY_MANAGER_ALLOCATOR_H
