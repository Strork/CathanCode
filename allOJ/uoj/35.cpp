#include<bits/stdc++.h>
using namespace std;
char s[100100];
int sa[100100];
int height[100100];
int rank[100100];
int temp[100100];
int cnt[1001];
int p[100100];
int n,m;

bool rua(int x,int y,int l) { return rank[x] == rank[y] && rank[x+l] == rank[y+l]; }
void solution()
{
	m = 260;
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = s[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for(int i, k = 0, l = 1; k < n; m = k)
	{
		k = 0;
		for(i = n - l + 1; i <= n; ++i) p[++k] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++k] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i)  sa[cnt[rank[p[i]]]--] = p[i];
		k = 0;
		for(i = 1; i <= n; ++i)
			temp[sa[i]] = rua(sa[i],sa[i-1],l)?k:++k;
		for(int i = 1; i <= n; ++i) rank[i] = temp[i];
		l <<= 1;
	}
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 1,j = 0,k; i <= n; ++i)
	{
		if(!(k = sa[rank[i] - 1])) 
		{
			j = 0;
			continue;
		}
		if(j) --j;
		while(s[i + j] == s[k + j]) ++j;
		height[rank[i]] = j;
	}
}

int main()
{
	scanf("%s",s+1);
	n = strlen(s+1);
	solution();
	for(int i = 1; i <= n; ++i)
	{
		printf("%d",sa[i]);
		if(i < n) printf(" ");
		else if(i == n) printf("\n");
	}
	for(int i = 2; i <= n; ++i)
	{
		printf("%d",height[i]);
		if(i < n) printf(" ");
		else if(i == n) printf("\n");
	}
	return 0;
}
