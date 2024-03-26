#include<bits/stdc++.h>
using namespace std;
int f[100100][15];
int a[100100][15];
int n;
int maxtime;

int read()
{
	int f = 1;
	int k = 0;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k*f;
}

void solution()
{
	for(int i = maxtime; i >= 0; --i)
	{
		for(int j = 1; j <= 11; ++j)
		{
			f[i][j] += a[i][j];
			f[i][j] += max(f[i+1][j-1],max(f[i+1][j],f[i+1][j+1]));
		}
	}
	//for(int i = 1; i <= 11; i++) cout<<f[2][i]<<endl;
	cout<<f[0][6]<<endl;
}

int main()
{
	while(n = read())
	{
		if(n == 0) break;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		maxtime = 0;
		for(int i = 1; i <= n; i++)
		{
			int x = read();
			int t = read();
			//cout<<t<<' '<<x<<endl;
			++a[t][x+1];
			if(t > maxtime) maxtime = t;
		}
		solution();
	}
	return 0;
}
