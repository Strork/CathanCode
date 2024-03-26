#include<bits/stdc++.h>
using namespace std;
int f[200100][33];
int n,m;

void ST()
{
	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
}

int read()
{
	int k = 0,f = 1;
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
	return k * f;
}

void RMQ(int x,int y)
{
	int k = 0;
	while((1 << (k + 1)) <= y - x + 1) ++k;
	printf("%d\n",max(f[x][k],f[y - (1 << k) + 1][k]));
}

int main()
{
	n = read();
	for(int i = 1; i <= n; ++i) f[i][0] = read();
	ST();
	m = read();
	for(int i = 1; i <= m; ++i)
	{
		int x = read();
		int y = read();
		RMQ(x,y);
	}
}
