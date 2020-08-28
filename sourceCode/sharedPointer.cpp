#include<iostream>
using namespace std;


class Point
{
    public:
        Point(int xVal = 0,int yVal = 0):x(xVal),y(yVal){}
        int getX() const{return x;}
        int getY() const{return y;}
        void setX(int xVal){x = xVal;}
        void setY(int yVal){y = yVal;}
    private:
        int x,y;
};


class RefPtr
{
    friend class SmartPtr;
    RefPtr(Point *ptr):p(ptr),count(1){}
    ~RefPtr(){delete p;}

    int count;
    Point *p;
};

class SmartPtr
{
    public:
        SmartPtr(Point *ptr):rp(new RefPtr(ptr)){}
        SmartPtr(const SmartPtr &other):rp(other.rp)
        {
            ++rp->count;
        }
        SmartPtr& operator=(const SmartPtr& other)
        {
            ++other.rp->count;
            if(--rp->count == 0)
                delete rp;
            rp = other.rp;
            return *this;
        }
        ~SmartPtr()
        {
            if(--rp->count == 0)
                delete rp;
        }
        void getCnt() const
        {
            cout<<rp->count<<endl;
        }
    private:
        RefPtr *rp;

};


int main()
{
    SmartPtr sp(new Point(5,3));
    sp.getCnt();
    SmartPtr ssp(sp);
    ssp.getCnt();
    system("pause");
}