#include <iostream>
using namespace std;
class Complex
{
public:
    Complex()
    {
        cout<<"call ctor function:"<<this<<endl;
    }
    ~Complex()
    {
        cout<<"call dtor function:"<<this<<endl;
    }

    Complex(int first, int second)
    {
        cout<<"call ctor with paramter function:"<<this<<endl;
    }
};

void test_string_ctor_dtor()
{
    string* pstr = new string;
    cout<< "str:"<<*pstr<<endl;

    //显式调用构造函数
    //! pstr->string::string("jjhou"); // error 'class std::basic_string<char> has no member string function'
    //string是对basic_string<char>的重命名 typedef
}

void test_new_array()
{
    //正确的输出是调用了三次构造函数和三次析构函数
    Complex* parray = new Complex[3];
    delete[] parray;//唤起三次dtor，没对每个object调用析构函数，有什么影响吗？
    //对class without ptr member可能没影响
    //对class with ptr member通常有影响

    //不加[]，只会调用一次析构函数，导致内存泄漏
    //用户友好的编译器会提示很多代码逻辑上的简单错误
    //delete parray;
}

//学编程时，要做行动的巨人，多手动多思考，少记忆理论
int test_operator_new_delete() {
    Complex* pc;
    try {
        //new expression 表达式
        Complex* tempObject = new Complex();

        //malloc memory 使用new操作符
        //operator new中调用的是系统函数malloc
        void* mem = operator new(sizeof(Complex));

        //convert pointer to Complex pointer type
        pc = static_cast<Complex*>(mem);

        //直接调用构造函数
        //error: cannot call constructor 'Complex::Complex' directly
        //! pc->Complex::Complex(1, 2);

        //欲直接调用ctor，可采用placement new方式
        new(pc) Complex(1, 2);

        //显式调用析构函数是可以的，会触发析构函数的调用
        pc->~Complex();

        //释放内存空间
        operator delete(pc);//operator delete :free an allocated object
        pc = nullptr;
    }
    catch (std::bad_alloc){
        //若申请内存失败，则不执行对象的构造函数

    }

    system("pause");
    return 0;
}

//重载全局的::operator new和::operator delete
void* myAlloc(size_t size)
{
    return malloc(size);
}

void myFree(void* ptr)
{
    return free(ptr);
}

//他们不可以被声明于一个命名空间中
void* operator new(size_t size)
{
    cout<< "jjhou global new()  \n"<<endl;
    return myAlloc(size);
}

void* operator new[](size_t size)
{
    cout<< "jjhou global new[]{}" <<endl;
    return myAlloc(size);
}

void operator delete(void* ptr)
{
    cout<<"jjhou global delete()"<<endl;
    myFree(ptr);
}

void operator delete[](void* ptr)
{
    cout<<"jjhou global delete[]()"<<endl;
    myFree(ptr);
}

#include "perClassAllocator.h"
//重载类的operator new和operator delete
//测试per-class allocator
void testPerClassAllocator()
{
    cout<< sizeof(perClassAllocator) <<endl;

    size_t const N = 100;
    perClassAllocator* p[N];

    for(int i=0; i < N; i++)
    {
        p[i] = new perClassAllocator(i);
    }

    //输出前10个pointers，比较其间隔
    for (int j = 0; j < N; ++j) {
        cout<< p[j] <<endl;
    }

    for (int k = 0; k < N; ++k) {
        delete p[k];
    }
}

int main()
{
    //test_new_array();
    testPerClassAllocator();
    cout<< "helllo world" <<endl;
    system("pause");
    return 0;
}