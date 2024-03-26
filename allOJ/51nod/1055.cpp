#include<bits/stdc++.h>
using namespace std;
int a[10010];
short f[10005][10005];
int n;

void solution()
{
	sort(a+1,a+1+n);
	int ans = 0;
	for(int k = n-1; k >= 2; --k)
	{
		int i = k-1;
		int j = k+1;
		while(i >= 1 && j <= n)
		{
			if(a[k]*2 > a[i] + a[j])
				++j;//1 3 5 6 8 9 10 12 13 14
			else if(a[k]*2 < a[i] + a[j])
				--i;
			else if(a[k]*2 == a[i] + a[j])
			{
				f[i][k] = f[k][j] + 1;
				if(f[i][k] > ans) ans = f[i][k];
				--i;
				++j;
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = 2;
	solution();
	return 0;
}
