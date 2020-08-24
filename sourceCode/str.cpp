#include<iostream>
#include<cstring>
using namespace std;

class MyStr
{
    public:
        MyStr(const char *str = nullptr);
        MyStr(const MyStr &other);
        ~MyStr();
        MyStr& operator=(const MyStr &other);
        MyStr operator+(const MyStr &other);
        bool operator==(const MyStr &other);
        int getLength();
        char *getCStr() const{return data;}
    private:
        char *data;

};

MyStr::MyStr(const char *str)
{
    if(str == nullptr)
    {
        data = new char[1];
        *data = '\0';
    }
    else
    {
        int len = strlen(str);
        data = new char[len+1];
        strcpy(data,str);
    }
    
}

MyStr::~MyStr()
{
    if(data)
    {
        delete[] data;
        data = nullptr;
    }
}

MyStr::MyStr(const MyStr &other)
{
    if(! other.data)
    {
        data = 0;
    }
    int len = strlen(other.data);
    data = new char[len+1];
    strcpy(data,other.data);
}

MyStr& MyStr::operator=(const MyStr &other)
{
    if(this != &other)
    {
        //释放原有的内存
        delete[] data;
        if(other.data == nullptr)
        {
            data = 0;
        }
        else
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data,other.data);
        }
             
    }
    return *this;
}

MyStr MyStr::operator+(const MyStr &other)
{
    MyStr newStr;
    if(!other.data)
    {
        newStr = *this;
    }
    else if(! data)
    {
        newStr = other;
    }
    else
    {
        newStr.data = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(newStr.data,data);
        strcpy(newStr.data,other.data);
    }
    return newStr;
}

bool MyStr::operator==(const MyStr &other)
{
    if(strlen(data) != strlen(other.data))
        return false;
    else
    {
        return strcmp(data,other.data)?false:true;
    } 
}

int MyStr::getLength()
{
    return strlen(data);
}

ostream& operator<<(ostream &os,const MyStr &str)
{
    os<<str.getCStr();
    return os;
}



int main()
{
    MyStr str("charfkda");
    cout<<str<<endl;
   
    system("pause");

    
}