#include<iostream>
#include<string>
#include<memory>
using namespace std;


template<typename T>
class UniquePointer
{
    public:
        using Pointer = T*;
        using Reference = T&;
        UniquePointer():ptr_(nullptr){}
        UniquePointer(Pointer ptr):ptr_(ptr){}
        UniquePointer(UniquePointer &&other):ptr_(other.ptr_)
        {
            other.ptr_ = nullptr;
        }
        UniquePointer& operator=(UniquePointer &&other)
        {
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
            return *this;
        }

        UniquePointer(const UniquePointer &other) = delete;
        UniquePointer& operator=(const UniquePointer &other) = delete;
        ~UniquePointer()
        {
            if(ptr_ != nullptr)
            {
                delete ptr_;

            }
        }

        operator bool()
        {
            return ptr_ != nullptr;
        }

        Pointer get()
        {
            return ptr_;
        }

        Reference operator*()
        {
            return *ptr_;
        }

        Pointer operator->()
        {
            return ptr_;
        }

        void reset(Pointer ptr = nullptr)
        {
            if(ptr_ != nullptr)
            {
                delete ptr_;
            }
            ptr_ = ptr;
        }



        
    private:
        Pointer ptr_;
};


struct Demo
{
    ~Demo()
    {
        cout<<"demo is deconstructed"<<endl;
    }
};


int main()
{
    UniquePointer<string> ptr(new string("hello"));
    
    UniquePointer<string> ptr1(move(ptr));
    if(! ptr)
    {
        cout<<"ptr is empty"<<endl;
    }
    if(ptr1)
    {
        cout<<"ptr1 is not empty"<<endl;
        cout<<*ptr1<<endl;
    }
    system("pause");
}