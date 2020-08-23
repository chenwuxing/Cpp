#include<iostream>
using namespace std;

class CStudent
{
    public:
        CStudent(int n,string nam,char s)
        {
            num = n;
            name = nam;
            sex = s;
        }
        ~CStudent(){}

    protected:
        int num;
        string name;
        char sex;
};

class CStudent1:public CStudent
{
    public:
        CStudent1(int n,string nam,char s,int a,string ad):CStudent(n,nam,s),age(a),addr(ad)
        {

        }
        void show()
        {
            cout<<"num: "<<num<<endl;
            cout<<"name: "<<name<<endl;
            cout<<"sex: "<<sex<<endl;
            cout<<"age: "<<age<<endl;
            cout<<"address: "<<addr<<endl;
        }
        ~CStudent1(){}

    private:
        int age;
        string addr;
};

int main()
{
    CStudent1 stud1(10010,"wang-li",'f',19,"115 beijing road shanghai");
    CStudent1 stud2(10011,"zhang-fun",'m',21,"213 shanghai road,beijing");
    stud1.show();
    stud2.show();
    system("pause");
}