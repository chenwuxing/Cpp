#include<iostream>
#include<assert.h>
using namespace std;

// 手写strcpy
char* strcpy(char *dest,char *src)
{
    char *ret = dest;
    assert(dest != nullptr);
    assert(src != nullptr);

    while(*src != '\0')
    {
        *(dest++) = *(src++);
    }
    *dest = '\0';
    return ret;
    
}



//考虑内存重叠的字符串拷贝函数
char* strcpy(char *dest,char *src)
{
    char *ret = dest;
    assert(dest != nullptr);
    assert(src != nullptr);

    memmove(dest,src,strlen(src)+1);
    return ret;
}

// 手写strcat函数
// 函数作用：将src所指向的字符串拼接在dest所指向的字符后面
//先找到dest的结尾再进行拼接
char *strcat(char *dest,const char *src)
{
    char *ret = dest;
    assert(dest != nullptr);
    assert(src != nullptr);

    while(*dest != '\0')
    {
        dest++;
    }
    while(*src != '\0')
    {
        *(dest++) = *(src++);
    }
    *dest = '\0';
    return ret;
}

// strcmp
//函数作用：把str1所指向的字符串与str2所指向的字符串做比较

int strcmp(const char *str1,const char *str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 > *str2)
            return 1;
        else if(*str1 < *str2)
            return -1;
        else
        {
            str1++;
            str2++;
        }
        
    }

    // 当有一个字符串已经走到尾了
    if(*str1 > *str2)
        return 1;
    else if(*str1 < *str2)
        return -1;
    else
        return 0;
}

// 感觉有些问题
char* strstr(char *str1,char *str2)
{
    char *s = str1;
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    if(*str2 == '\0')
        return nullptr;
    
    while(*s != '\0')
    {
        char *s1 = s;
        char *s2 = str2;
        while(*s1 != nullptr && *s2 != nullptr && *s1 == *s2)
        {
            s1++;
            s2++;
        }
        if(*str2 == '\0')
            return s;
        if(*s1 == '\0' && *s2 != '\0')
            return nullptr;
        s++;
    }

    return nullptr;
    
}


// memcpy
//模拟实现函数memcpy从存储区src复制n个字符到存储区dst
void* memcpy(void *dest,void *src,size_t num)
{
    char *sDst = (char*)src;
    char *sSrc = (char*)dest;
    assert(dest != nullptr);
    assert(src != nullptr);
    while(num--)
    {
        *sDst++ = *sSrc++;

    }
    return dest;

}

// 相当于考虑内存重叠的memcpy函数，从存储区src复制n个字符到存储区dst
void* memmove(void* dst,const void* src,size_t n)
{
    char *sDst;
    char *sSrc;
    sDst = (char*)dst;
    sSrc = (char*)src;

    if(sDst > sSrc && (sSrc + n > sDst))
    {
        sDst = sDst + n -1;
        sSrc = sSrc + n -1;
        while(n--)
        {
            *sDst-- = *sSrc--;

        }
    }
    else
    {
        while(n--)
        {
            *sDst++ = *sSrc++;
        }
        
    }
    return dst;
}