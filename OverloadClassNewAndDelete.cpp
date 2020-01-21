//
// Created by Administrator on 2020\1\21 0021.
//

#include "OverloadClassNewAndDelete.h"

void *OverloadClassNewAndDelete::operator new(size_t size) {
    OverloadClassNewAndDelete* p = (OverloadClassNewAndDelete*)malloc(size);
    cout << "Foo::operator new(), size=" << size << "\t  return: " << p << endl;

    return p;
}

void *OverloadClassNewAndDelete::operator new[](size_t size) {
    OverloadClassNewAndDelete* p = (OverloadClassNewAndDelete*)malloc(size);  //crash, 問題可能出在這兒
    cout << "Foo::operator new[](), size=" << size << "\t  return: " << p << endl;

    return p;
}

void OverloadClassNewAndDelete::operator delete(void *deadObject, size_t size) {
    cout << "Foo::operator delete(), pdead= " << deadObject << "  size= " << size << endl;
    free(deadObject);
}

void OverloadClassNewAndDelete::operator delete[](void *deadObject, size_t size) {
    cout << "Foo::operator delete[](), pdead= " << deadObject << "  size= " << size << endl;

    free(deadObject);
}
