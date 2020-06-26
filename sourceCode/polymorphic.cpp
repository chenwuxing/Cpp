#include<iostream>
using namespace std;

typedef void(*Fun)();
class Base
{
    public:
        virtual void f(){cout<<"Base::f()"<<endl;}
        virtual void g(){cout<<"Base::g()"<<endl;}
        virtual void h(){cout<<"Base::h()"<<endl;}

};

class Derive:public Base
{
    public:
        void f() override {cout<<"Derived f()"<<endl;}
        virtual void f1() {cout<<"Derive::f1()"<<endl;}
        virtual void g1() {cout<<"Derive::g1()"<<endl;}
        virtual void h1() {cout<<"Derive::h1()"<<endl;}
};


// 多重继承测试
class Base1
{
    public:
        virtual void f() {cout<<"Base1::f()"<<endl;}
        virtual void g() {cout<<"Base1::g()"<<endl;}
        virtual void h() {cout<<"Base1::h()"<<endl;}

};

class Base2
{
    public:
        virtual void f() {cout<<"Base2::f()"<<endl;}
        virtual void g() {cout<<"Base2::g()"<<endl;}
        virtual void h() {cout<<"Base2::h()"<<endl;}
};

class Base3
{
    public:
        virtual void f() {cout<<"Base3::f()"<<endl;}
        virtual void g() {cout<<"Base3::g()"<<endl;}
        virtual void h() {cout<<"Base3::h()"<<endl;}

};

class Derive1:public Base1,public Base2,public Base3
{
    public:
        void f() override {cout<<"Derive1::f()"<<endl;}
        virtual void g1() {cout<<"Derive1::g1()"<<endl;}
};



int main()
{
    // 单继承无覆盖的情形
    // Derive dObj;
    // Fun pFun = nullptr;
    // cout<<"virtual table address:"<<(unsigned long*)(&dObj)<<endl;
    // cout<<"virtual table first function address:"<<(unsigned long*)*(unsigned long*)(&dObj)<<endl;

    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj));
    // pFun();
    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj)+1);
    // pFun();
    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj)+2);
    // pFun();
    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj)+3);
    // pFun();
    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj)+4);
    // pFun();
    // pFun = (Fun)*((unsigned long*)*(unsigned long*)(&dObj)+5);
    // pFun();

    //多继承无覆盖
    // 多继承时虚函数表存储方式发生了变化，在多继承时可以认为有多个虚表指针指向不同的虚函数表
    Derive1 d1Obj;
    Fun pFun = nullptr;
   
    // base1's vtable
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 0) + 0);
    //等价于:pFun = (Fun)*((unsigned long*)*(unsigned long*)((unsigned long*)&d1Obj+0) + 0)
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 0) + 1);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 0) + 2);
    pFun();

    //Derive1's vtable
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 0) + 3);
    pFun();
    // the tail of the vtable
    // pFun = (Fun)pVtab[0][4];
    // pFun();
    // pFun = (Fun)pVtab[0][5];
    // cout<<pFun<<endl;

    //Base2's vtable
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 1) + 0);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 1) + 1);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 1) + 2);
    pFun();
    //the tail of the vtable
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 1) + 3);
    cout<<pFun<<endl;

    //Base3's vtable
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 2) + 0);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 2) + 1);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 2) + 2);
    pFun();
    pFun = (Fun)* ((unsigned long*)* ((unsigned long*)&(d1Obj) + 2) + 3);
    cout<<pFun<<endl;







    system("pause");
}

