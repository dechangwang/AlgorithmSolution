#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
void get_next(string &m, int *next)     //next数组要保证比m要大
{
    next[0]=-1;
    int i=0, j=-1;
    while(i<m.size())
    {
        if(j==-1 || m[i]==m[j])      //j在原串上， i在模式串上
            next[++i] = ++j;
        else
            j = next[j];
    }
}

int kmp(string &y, string &m,int *next )        //找到则返回索引
{
    if(m.size()>y.size())   return 0;           //原串比模式串还小
    int i=0, j=0, cnt=0;
    while(i<y.size())
    {
        if(j==-1||y[i]==m[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
        if(j==m.size()) cnt++;
    }
    return cnt;
}

int main()
{
    string m, y;
    int next[10005];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>y;
        get_next(m, next);
        cout<<kmp(y, m, next)<<endl;
    }
    return 0;
}