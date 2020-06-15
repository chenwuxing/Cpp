#include<iostream>
using namespace std;
template<typename T>
class SharedPointer
{
    public:
        SharedPointer(T *ptr = nullptr,const std::function<void(T*)> &del = Deleter()):
            p(ptr),use_c(new std::size_t(ptr != nullptr)),deleter(del){}
        SharedPointer(const SharedPointer &);
        SharedPointer(SharedPointer &&) noexcept;
        SharedPointer& operator=(SharedPointer);
        ~SharedPointer() {release();}

        std::size_t use_count(){return *use_c;}
        bool unique() const {return *use_c == 1;}
        operator bool() const {return p != nullptr;}
        void reset(T* ptr = nullptr,const std::function<void(T*)> &del = Deleter());
        void swap(SharedPointer<T>&);
        T* get() const {return p;}
        T& operator*() const {return *p;}
        T* operator->()const {return p;}
        
    private:
        std::size_t *use_c;
        T *p;
        std::function<void(T*)> deleter;
        void release;

};

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &rhs):use_c(rhs.use_c),p(rhs.p),deleter(rhs.deleter)
{
    ++*use_c;
}

template<T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer rhs)
{
    SharedPointer<T> temp(rhs);
    swap(temp);
    return *this;
}

template<typename T>
void SharedPointer::swap(SharedPointer<T> &rhs)
{
    using std::swap;
    swap(use_c,rhs.use_c);
    swap(p,rhs.p);
    swap(deleter,rhs.deleter);
}

template<typename T>
void SharedPointer<T>::release()
{
    if(--*use_c == 0)
    {
        if(p)
        {
            deleter(p);
        }
        delete use_c;
    }
    use_c = nullptr;
    p = nullptr;
}