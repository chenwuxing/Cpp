#include<iostream>
#include<vector>

using namespace std;


vector<string> split(const string &text,const string &pattern)
{
    if(text == "")
        return {};
    
    vector<string> res;

    string strs = text + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        string temp = strs.substr(0,pos);
        res.push_back(temp);
        strs = strs.substr(pos + 1,strs.size());
        pos = strs.find(pattern);

    }

    return res;
}