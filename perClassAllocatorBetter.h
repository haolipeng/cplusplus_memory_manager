//
// Created by Administrator on 2020\1\21 0021.
//

#ifndef CPLUSPLUS_MEMORY_MANAGER_PERCLASSALLOCATORBETTER_H
#define CPLUSPLUS_MEMORY_MANAGER_PERCLASSALLOCATORBETTER_H
#include <unistd.h>

class Airplane {
private:
    struct AirplaneRep{
        unsigned long miles;
        char type;
    };
private:
    union {
        AirplaneRep rep;
        Airplane* next; //指向下一个节点的指针
    };
public:
    unsigned long getMiles()
    {
        return rep.miles;
    }

    char getType()
    {
        return rep.type;
    }

    void set(unsigned long m,char t)
    {
        rep.type = t;
        rep.miles = m;
    }

public:
    static void* operator new(size_t size);
    static void operator delete(void* deadObject, size_t size);

private:
    static const int BLOCK_SIZE;
    static Airplane* headOfFreeList;
};

#endif //CPLUSPLUS_MEMORY_MANAGER_PERCLASSALLOCATORBETTER_H
