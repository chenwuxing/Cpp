#include<iostream>
using namespace std;

class CSingleton
{
    private:
        CSingleton(){}
        static CSingleton *m_pInstance;
    public:
        static CSingleton* getInstance()
        {
            if(m_pInstance == nullptr)
                m_pInstance = new CSingleton();
            return m_pInstance;
        }
};

CSingleton* CSingleton::m_pInstance = nullptr;

int main()
{
    CSingleton *s1 = CSingleton::getInstance();
    CSingleton *s2 = CSingleton::getInstance();
    if(s1 == s2)
        cout<<"s1 == s2"<<endl;
    system("pause");
}