#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll n;
int sum[1001000];
int maxn = 0;

void pre()
{
	for(int i = 1; i <= 1000000; ++i)
	{
		sum[i] = i ^ sum[i-1];
	}
}

void solution()
{
	
}

int main()
{
	scanf("%d",&T);
	pre();
	while(T--)
	{
		scanf("%lld",&n);
		solution();
	}
	return 0;
}
