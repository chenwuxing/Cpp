#include<iostream>
using namespace std;
//共用体内变量的的默认对齐方式，必须以最长的double（8byte）对齐
union A
{
    int a[5];
    char b;
    double c;
};

struct B{
    char a;
    double b;
    int c;
}test_struct_b;

int main()
{
    cout<<sizeof(A)<<endl;   //24
    cout<<sizeof(test_struct_b)<<endl;  //24
    system("pause");

}
