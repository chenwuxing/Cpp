template<typename T,typename D = std::function<void(T*)>>
class UniquePointer
{
    public:
        UniquePointer(const UniquePointer&) = delete;
        UniquePointer& operator=(const UniquePointer&) = delete;

        UniquePointer(T *raw_p = nullptr,const std::function<void(T*)> del = Deleter())
            p(raw_p),deleter(del)   {}
        UniquePointer(UniquePointer &&) noexcept;
        UniquePointer& operator=(UniquePointer &&) noexcept;
        ~UniquePointer() {deleter(p);}

        T* get() const {return p;}
        T* release() noexcept;
        void reset(T *ptr = nullptr) noexcept;
        void swap(UniquePointer<T>&);

        operator bool() const {return p != nullptr;}
        D& get_deleter() noexcept;
        const D& get_deleter() const noexcept;

        T& operator*() const {return *p;}
        T* operator->() const {return p;}
    
    private:
        T *p;
        std::function<void(T*)> deleter = D();
};

template<typename T,typename D>
void UniquePointer<T,D>::swap(UniquePointer<T> &rhs)
{
    using std::swap;
    swap(p,rhs.p);
    swap(deleter,rhs.deleter);
}

template<typename T,typename D>
T* UniquePointer<T,D>::release() noexcept
{
    T *tmp = p;
    p = nullptr;
    return tmp;
}

template<typename T,typename D>
void UniquePointer<T,D>::reset(T *ptr) noexcept
{
    UniquePointer<T> temp(ptr);
    swap(temp);
}