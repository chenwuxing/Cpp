#include<iostream>
#include<limits.h>
using namespace std;


enum Status{kValid=0,kNull,kOverfollow,kChar};
int status = kValid;

int strToInt(char *str)
{
    int flag = 1;
    if(str == NULL)
    {
        status = kNull;
        return 0;
    }
    
    while(isspace(*str))
        str++;
    
    if(*str == '-')
    {
        flag = -1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }

    // 计算数值部分
    long res = 0;
    while(*str != '\0')
    {
        if(*str >= '0' && *str <= '9')
        {
            res = res * 10 + (*str) - '0';
            if(res >= INT_MAX && flag == 1)
            {
                status = kOverfollow;
                return INT_MAX;
            }
            if(res > INT_MAX && flag == -1)
            {
                status = kOverfollow;
                return INT_MIN;
            }
            str++;
        }
        else
        {
            status = kChar;
            break;
        }

    }

    return res * flag;

    
}


int main()
{
    char str[80];
    cout<<"请输入字符串："<<endl;
    cin.getline(str,80);

    int result = strToInt(str);
    cout<<result<<endl;

    system("pause");
}