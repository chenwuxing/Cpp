#ifndef MYSTRING
#define MYSTRING




class MyString
{
    private:
        char *data;
    
    public:
        MyString(const char *cstr=0);
        MyString(const MyString &str);
        MyString& operator=(const MyString &str);
        ~MyString();
        char* getCStr() const {return data;}
};

#include<cstring>
inline
MyString::MyString(const char *cstr)
{
    if(cstr)
    {
        data = new char[strlen(cstr) + 1];
        strcpy(data,cstr);
    }
    else
    {
        data = new char[1];
        *data = '\0';
    }
    
}

inline
MyString::MyString(const MyString &str)
{
    data = new char[strlen(str.data) + 1];
    strcpy(data,str.data);
}

inline
MyString& MyString::operator=(const MyString &str)
{
    if(this == &str)
    {
        return *this;
    }
    delete[] data;
    data = new char[strlen(str.data) + 1];
    strcpy(data,str.data);
    return *this;
}

inline
MyString::~MyString()
{
    delete[] data;
}

#include<iostream>
using namespace std;

ostream& operator<<(ostream &os,const MyString &str)
{
    os<<str.getCStr();
    return os;
}



#endif