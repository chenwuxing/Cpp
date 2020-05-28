#include<iostream>
#include<string>
using namespace std;


template<typename T,typename D>
class Origin
{
    
    
    public:
        Origin(T first,D second):x(first),y(second)
        {
            cout<<"original template"<<endl;
        }

    private:
        T x;
        D y;

};


// 全特化
template<>
class Origin<int,char>
{
    private:
        int x;
        char y;
    
    public:
        Origin(int first,char second):x(first),y(second)
        {
            cout<<"complete specialization"<<endl;
        }
    

};

// 个数偏特化
template<typename D>
class Origin<char,D>
{
    private:
        char x;
        D y;
    public:
        Origin(char first,D second):x(first),y(second)
        {
            cout<<"number partial specialization"<<endl;
        }
};

//范围偏特化-指针
template<typename T,typename D>
class Origin<T*,D*>
{
    private:
        T* x;
        D* y;
    public:
        Origin(T *first,D *second):x(first),y(second)
        {
            cout<<"range partial specialization"<<endl;
        }
};

// 范围偏特化-const
template<typename T,typename D>
class Origin<const T,const D>
{
    private:
        T x;
        D y;
    public:
        Origin(T first,D second):x(first),y(second)
        {
            cout<<"const partial specialization"<<endl;
        }
};


int main()
{
    int a = 7;
    string b("chense");
    Origin<int,int> test1(66,666);
    Origin<int,char> test2(66,'a');
    Origin<char,bool> test3('A',true);
    Origin<int*,int*> test4(&a,&a);
    Origin<const int,const int> test5(6,6);
    system("pause");

};




