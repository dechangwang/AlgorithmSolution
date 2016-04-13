#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
void get_next(string &m, int *next)     //next����Ҫ��֤��mҪ��
{
    next[0]=-1;
    int i=0, j=-1;
    while(i<m.size())
    {
        if(j==-1 || m[i]==m[j])      //j��ԭ���ϣ� i��ģʽ����
            next[++i] = ++j;
        else
            j = next[j];
    }
}

int kmp(string &y, string &m,int *next )        //�ҵ��򷵻�����
{
    if(m.size()>y.size())   return 0;           //ԭ����ģʽ����С
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