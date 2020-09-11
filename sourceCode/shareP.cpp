#include<bits/stdc++.h>
using namespace std;

template<typename T> class SmartPointer;

template<typename T> 
class Ref
{
   friend class SmartPointer<T>;
   Ref(T* pointer):p(pointer),count(1){};
   ~Ref(){delete p;}
   T *p;
   int count;
};


template<typename T>
class SmartPointer
{
   public:
      SmartPointer(T* pointer):pMeta(new Ref<T>(pointer)){}
      SmartPointer(const SmartPointer<T> &other):pMeta(other.pMeta)
      {
         ++pMeta->count;
      }
      SmartPointer<T>& operator=(const SmartPointer<T> &other)
      {
         ++other.pMeta->count;
         if(--pMeta->count == 0)
            delete pMeta;
         pMeta = other.pMeta;
         return *this;
      }
      ~SmartPointer()
      {
         if(--pMeta->count == 0)
            delete pMeta;
      }
      void getCount()
      {
         cout<<pMeta->count<<endl;
      }



   private:
      Ref<T> *pMeta;


};

struct pointer
{
   public:
      pointer(int x = 0,int y = 0):xVal(x),yVal(y){}
      int getX() const{return xVal;}
      int getY() const{return yVal;}
      void setX(int p){xVal = p;}
      void setY(int y){yVal = y;}
   private:
      int xVal;
      int yVal;
};



int main()
{
   SmartPointer<pointer> sp(new pointer);
   sp.getCount();
   SmartPointer<pointer> ssp(sp);
   ssp.getCount();
   system("pause");
}