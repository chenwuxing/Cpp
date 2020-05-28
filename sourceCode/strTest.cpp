#include "str.h"

#include <iostream>
using namespace std;

int main()
{
    MyString s1("hello");
    MyString s2("world");
    MyString s3(s1);
    cout<<s3<<endl;
    s3 = s2;
    cout<<s3<<endl;
    cout<<s2<<endl;
    cout<<s1<<endl;
    system("pause");
}