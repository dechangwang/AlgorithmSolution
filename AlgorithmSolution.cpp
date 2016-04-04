// AlgorithmSolution.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define SIZE 10005

using namespace std;

void getNext(string &m,int next[]){
	next[0] = -1;
	int i = 0,k = -1;

	while(i<m.size())
	{
		if(k == -1 || m[i] == m[k])
			next[++i] = ++k;
		else
			k = next[k];
	}

}
//kmp算法
int kmp(string &t,string &p, int * next)
{
	if(t.size() < p.size())
		return 0;
	int i = 0,k = 0,cnt = 0;
	while (i< t.size())
	{
		if(k == -1 || t[i] == p[k])
		{
			++i;
			++k;
		}else
			k = next[k];
		if(k == p.size())
		{
			cnt ++;
			//k = next[k];
		}
			
	}
	return cnt;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string p,t;
	int next[SIZE];// = {-1};
	int n;
	cin>>n;
	if(n == 3)
		cout<<"OK"<<endl;
	while (n--)
	{
		cin>>p>>t;
		
		getNext(p,next);
		cout<<kmp(t,p,next)<<endl;
	}
	getchar();
	getchar();
	return 0;
}

