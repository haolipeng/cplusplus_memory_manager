#include <cstdlib>//malloc,free
#include "common.h"//#include <iostream>
#include "perClassAllocator.h"
#include "perClassAllocatorBetter.h"
#include "OverloadClassNewAndDelete.h"
#include "allocator.h"

using namespace std;
//////////////////////////各种宏开关////////////////////////////////
#define USE_OPERATOR_NEW_DELETE 0           //是否启用重载new和delete

#if USE_OPERATOR_NEW_DELETE
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
#endif

/*
 * 测试1:string类型是否可直接调用构造函数
 * */
void test_call_ctor_directly()
{
    //C++ 默认string类型对象
    auto* pstr = new string;
    cout<< "str:"<<*pstr<<endl;

    //显式调用构造函数
    //! pstr->string::string("jjhou"); // error 'class std::basic_string<char> has no member string function'
    //string是对basic_string<char>的重命名 typedef

    //自定义对象
    A* pA = new A(1);         	//ctor. this=0x5f6ff8 id=1
    cout << pA->id << endl;   	//1
//!	pA->A::A(3);                //in GCC : [Error] cannot call constructor 'A::A' directly
    delete pA;                	//dtor. this=0x5f6ff8

    //simulate new 模拟new操作
    void* p = ::operator new(sizeof(A));
    cout << "p=" << p << endl; 	//p=000307A8
    pA = static_cast<A*>(p);
//!	pA->A::A(2);				//in VC6 : ctor. this=000307A8 id=2
    //in GCC : [Error] cannot call constructor 'jj02::A::A' directly

    cout << pA->id << endl;     //in VC6 : 2
    //in GCC : 0

    //simulate delete 模拟delete操作
    pA->~A();					//dtor. this=000307A8
    ::operator delete(pA);		//free()
}

/*
 * 测试2:delete和delete[]调用析构函数的次数
 * */
void test_new_array()
{
    //正确的输出是调用了三次构造函数和三次析构函数
    auto* array = new Complex[3];
    delete[] array;//唤起三次dtor，如果没对每个object调用析构函数，有什么影响吗？
    //对class without ptr member可能没影响
    //对class with ptr member通常有影响，ptr指向的内存空间需手动释放

    //不加[]，只会调用一次析构函数，导致内存泄漏
    //用户友好的编译器会提示很多代码逻辑上的简单错误
    //delete array;
}
/*
 * 测试3:测试operator new和operator delete
 * */
void test_operator_new_delete() {
    Complex* pc;
    try {
        //new expression 表达式
        auto* tempObject = new Complex();
        delete tempObject;

        //申请内存使用new操作符
        //operator new中调用的是系统函数malloc
        void* mem = operator new(sizeof(Complex));

        //convert pointer to Complex pointer type
        // 用户想申请的是指向Complex的指针
        pc = static_cast<Complex*>(mem);

        //直接调用构造函数，报错
        //error: cannot call constructor 'Complex::Complex' directly
        //! pc->Complex::Complex(1, 2);

        //欲直接调用ctor，可采用placement new方式
        new(pc) Complex(1, 2);

        //显式调用析构函数是可以的
        pc->~Complex();

        //operator delete 操作符释放内存空间
        operator delete(pc);//operator delete :free an allocated object
    }
    catch (std::bad_alloc){
        //若申请内存失败，则不执行对象的构造函数
    }
}

/*
 * 测试4:基础版的内存申请器
 * */
void test_per_class_allocator_1()
{
    cout << "\ntest_per_class_allocator_1().......... \n";
    cout<< sizeof(perClassAllocator) <<endl;

    size_t const N = 100;
    perClassAllocator* p[N];

    for(int i=0; i < N; i++)
    {
        p[i] = new perClassAllocator(i);
    }

    //输出前10个pointers，比较其间隔
    for (auto & j : p) {
        cout<< j <<endl;
    }

    for (auto & k : p) {
        delete k;
    }
}

/*
 * 测试5:改进版的内存申请器
 * */
void test_per_class_allocator_2()
{
    cout << "\ntest_per_class_allocator_2().......... \n";

    cout << sizeof(Airplane) << endl;    //8

    size_t const N = 100;
    Airplane* p[N];

    for (int i=0; i< N; ++i)
        p[i] = new Airplane;


    //隨機測試 object 正常否
    p[1]->set(1000,'A');
    p[5]->set(2000,'B');
    p[9]->set(500000,'C');
    cout << p[1] << ' ' << p[1]->getType() << ' ' << p[1]->getMiles() << endl;
    cout << p[5] << ' ' << p[5]->getType() << ' ' << p[5]->getMiles() << endl;
    cout << p[9] << ' ' << p[9]->getType() << ' ' << p[9]->getMiles() << endl;

    //輸出前 10 個 pointers, 用以比較其間隔
    for (int i=0; i< 10; ++i)
        cout << p[i] << endl;

    for (int i=0; i< N; ++i)
        delete p[i];
}
/*
 * 测试重载后的new和delete*/
void test_overload_operator_new_and_array_new()
{
    cout << "\ntest_overload_operator_new_and_array_new().......... \n";

    cout << "sizeof(OverloadClassNewAndDelete)= " << sizeof(OverloadClassNewAndDelete) << endl;

    auto* p = new OverloadClassNewAndDelete(7);
    delete p;

    auto* pArray = new OverloadClassNewAndDelete[5];
    delete [] pArray;

    {
        cout << "testing global expression ::new and ::new[] \n";
        // 這會繞過 overloaded new(), delete(), new[](), delete[]()
        // 但當然 ctor, dtor 都會被正常呼叫.

        p = ::new OverloadClassNewAndDelete(7);
        ::delete p;

        pArray = ::new OverloadClassNewAndDelete[5];
        ::delete [] pArray;
    }
}
/*
 * 测试placement new*/
void test_overload_placement_new()
{
    //重载class member operator new()，可写出多个版本，前提是每个版本的必须有独特的参数，其中第一个参数的类型
    //必须是size_t,其余参数以new所制定的placement arguments为初值。
    cout<< "\n\ntest_overload_placement_new().................................." <<endl;
    cout<<"size of OverloadClassNewAndDelete:"<<sizeof(OverloadClassNewAndDelete)<<endl;
    OverloadClassNewAndDelete start;

    auto* p1 = new OverloadClassNewAndDelete; //op-new(size_t)
    auto* p2 = new (&start) OverloadClassNewAndDelete; //op-new(size_t,void*)
    auto* p3 = new (100) OverloadClassNewAndDelete;//op-new(size_t,long)
    auto* p4 = new (100, 'a') OverloadClassNewAndDelete;//op-new(size_t,long,char)

    //释放全部的内存
    delete p1;
    //delete p2;//此处p2不是动态申请的内存,无法使用delete进行释放
    delete p3;
    delete p4;
}
/*
 * 测试allocator类申请和释放功能*/
#include <complex>
class Goo
{
public:
    complex<double> c;
    string str;
    static Common::allocator myAlloc;
public:
    Goo()= default;
    ~Goo() = default;
    Goo(const complex<double>& x):c(x) {}
    static void* operator new(size_t size)
    {
        return myAlloc.allocate(size);
    }

    static void operator delete(void* ptr, size_t size)
    {
        return myAlloc.deallocate(ptr, size);
    }
};
//静态变量初始化
Common::allocator Goo::myAlloc;

void test_common_allocator()
{
    Goo* p[100];
    cout<<"sizeof(Goo)="<< sizeof(Goo)<<endl;

    for (int i = 0; i < 17; ++i) {
        p[i] = new Goo(complex<double>(i,i));
        cout<<p[i]<<""<<p[i]->c<<endl;
    }

    for (int j = 0; j < 17; ++j) {
        delete p[j];
    }
}

int main()
{
    cout<<"begin testing!"<<endl;
    //test_new_array();
    //test_call_ctor_directly();
    //test_per_class_allocator_1();
    //test_per_class_allocator_2();
    //test_overload_operator_new_and_array_new();
    //test_overload_placement_new();
    test_common_allocator();
    cout<< "test is done!" <<endl;
    system("pause");
    return 0;
}