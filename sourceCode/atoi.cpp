#include<iostream>
#include<limits>
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
    if(*str == '+')
    {
        str++;
    }

    // 计算数值部分
    int res = 0;
    while(*str != '\0')
    {
        if(*str >= '0' && *str <= '9')
        {
            res = res * 10 + (*str) - '0';
            if(res < 0)
            {
                if(flag == 1)
                {
                    res = std::numeric_limits<int>::max();
                }
                if(flag == -1)
                {
                    res = std::numeric_limits<int>::min();
                }
                status = kOverfollow;
                return res;
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