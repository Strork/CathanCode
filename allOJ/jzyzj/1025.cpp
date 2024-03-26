#include<bits/stdc++.h>
using namespace std;
int a[120][10];//max
int b[120][10];//min
int n;

void ST()
{
	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
			b[i][j] = min(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
		}
}

void rangemax(int x,int y)
{
	int k = 0;
	while((1 << (k + 1)) <= y - x + 1) ++k;
	printf("%d\n",max(a[x][k], a[y - (1 << k) + 1][k]));
}

void rangemin(int x,int y)
{
	int k = 0;
	while((1 << (k + 1)) <= y - x + 1) ++k;
	printf("%d\n",min(b[x][k], b[y - (1 << k) + 1][k]));
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i][0];
		b[i][0] = a[i][0];
	}
	ST();
	rangemax(1,n);
	rangemin(1,n);
	int sum = 0;
	for(int i = 1; i <= n; ++i)
		sum += a[i][0];
	printf("%d\n",sum/n);
	return 0;
}
