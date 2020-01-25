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

/*声明宏*/
#define DECLARE_POOL_ALLOC()\
public:\
    static void* operator new(size_t size) { return myAlloc.allocate(size); }\
    static void operator delete(void* ptr) { return myAlloc.deallocate(ptr, 0); }\
protected:\
    static Common::allocator myAlloc;

/*实现宏*/
#define IMPLEMENT_POOL_ALLOC(class_name)\
Common::allocator class_name::myAlloc;

#endif //CPLUSPLUS_MEMORY_MANAGER_ALLOCATOR_H
