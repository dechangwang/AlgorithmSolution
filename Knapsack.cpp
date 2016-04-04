#include "stdafx.h"
#include<iostream>

//#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;
	
int value[505],weight[505];
int dp[505][100002];
int main()
{

	int N,M;

	cin>>N>>M;

	for(int i = 1;i<=N;i++)
	{
		cin>>weight[i]>>value[i];
	}

	for(int i = 1;i<=N;i++)
	{
		for(int j = 0;j<=M;j++)
		{
			if(j< weight[i])
			{
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j],(value[i]+dp[i-1][j-weight[i]]));
			}
		}
	}
	cout<<dp[N][M];
	getchar();
	getchar();
	return 0;
}


/*
scanf_s


int dp[502][100002];  
int need[502], value[502];  
  
int main()  
{  
    int n, m;  
    while(scanf("%d %d", &n, &m) != EOF)  
    {  
        for(int i=1; i<=n; i++)  
            scanf("%d %d", &need[i], &value[i]);  
        for(int j=0; j<=m; j++)  
            dp[0][j] = 0;  
        for(int i=1; i<=n; i++)  
            for(int j=0; j<=m; j++)  
                if(j<need[i])  
                    dp[i][j] = dp[i-1][j];  
                else  
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-need[i]] + value[i]);  
        printf("%d\n", dp[n][m]);  
    }  
    return 0;  
}   
*/