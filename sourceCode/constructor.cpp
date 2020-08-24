#include<iostream>
using namespace std;

class CBase
{
    public:
        CBase()
        {
            cout<<"CBase::CBase()"<<endl;
        }
        ~CBase()
        {
            cout<<"CBase::~CBase()"<<endl;
        }
};

class CBase1:public CBase
{
    public:
        CBase1()
        {
            cout<<"CBase1::CBase1()"<<endl;
        }
        ~CBase1()
        {
            cout<<"CBase1::~CBase1()"<<endl;
        }
};

class CDerive
{
    public:
        CDerive()
        {
            cout<<"CDerive::CDerive()"<<endl;
        }
        ~CDerive()
        {
            cout<<"CDerive::~CDerive()"<<endl;
        }
};

class CDerive1:public CBase1
{
    private:
        CDerive m_derive;
    public:
        CDerive1()
        {
            cout<<"CDerive1::CDerive1()"<<endl;
        }
        ~CDerive1()
        {
            cout<<"CDerive1::~CDerive1()"<<endl;
        }
};

int main()
{
    CDerive1 derive;
    system("pause");
}

