#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define L 2000005

//#define max(a,b) ((a)>(b)?(a):(b))


using namespace std;

int p[L];
char s[L];
void maxPalindrome(string &str)
{
	s[0] = '$';
	s[1] = '#';
	int k = 2;
	int id = 0,mx = 0;
	for(int i= 0;i<str.size();i++)
	{
		s[k++] = str[i];
		s[k++] = '#';
	}
	int len = str.size()*2 +2;
	for(int i = 1;i<len;i++)
	{
		if(mx > i)
		{
			p[i]= min(p[2*id-i],p[id]+id-i);
		}else
		{
			p[i] = 1;
		}

		while(s[i+p[i]]==s[i-p[i]])
            p[i]++;
		if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
	}
	int maxvalue = 0;
	for(int i = 0;i<len;i++)
	{
		if(p[i] >maxvalue)
		{
			maxvalue = p[i];
		}
	}
	cout<<maxvalue - 1<<endl;

}

int main()
{

	int n;
	cin>>n;
	string str;
	while(n--)
	{
		cin>>str;
		maxPalindrome(str);
	}
	getchar();
	getchar();
	return 0;
}


