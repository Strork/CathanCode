#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int b[110];
int f[110][110];
int sum[110];
int cost[110][110];

void pre()
{
	for(int i = 1; i <= m; ++i) 
	{
		sum[i] = b[i] + sum[i - 1];
		//cout<<sum[i]<<' ';
	}//cout<<endl;
	for(int i = 1; i <= m; ++i)
	{
		for(int j = i; j <= m; ++j)
		{
			cost[i][j] = sum[j] - sum[i - 1];
		}
	}
}

void solution()
{
	for(int p = 1; p <= m; ++p)
	{
		for(int i = 1; i <=m; i++)
		{
			int j = i + p - 1;
			if(j > m) break;
			for(int k = i; k < j; ++k)
			{
				if(f[i][j] > f[i][k] + f[k+1][j] + cost[i][j] + j - i - 1 || f[i][j] == 0)
					f[i][j] = f[i][k] + f[k+1][j] + cost[i][j] + j - i - 1;
			}
		}
	}
	cout<<f[1][m]<<endl;
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= m; ++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	++m;
	b[1] = a[1] - 1;
	for(int i = 2; i < m; ++i)
		b[i] = a[i] - a[i-1] - 1;
	b[m] = n - a[m-1];
	//for(int i = 1; i <= m; i++) cout<<b[i]<<' ';cout<<endl;
	pre();
	solution();
	return 0;
}
