#include<bits/stdc++.h>
using namespace std;
int sa[100100];
int p[100100];
int rank[100100];
int c[30];
char ch[100100][12];
int n;
int m = 0;
int len;


void solution()
{
	for(int i = 1; i <= n; ++i)
		sa[i] = i;
	for(int k = 10; k; --k)
	{
		memset(c,0,sizeof(c));
		for(int i = 1; i <= n; ++i) rank[i] = ch[i][k]-'a'+1,p[i] = sa[i];
		for(int i = 1; i <= n; ++i) ++c[rank[i]];
		for(int i = 1; i <= 26; ++i) c[i] += c[i-1];
		for(int i = n; i; --i) sa[c[rank[p[i]]]--] = p[i];
	}
	for(int i = 1; i <= n; ++i)
		cout<<sa[i]<<endl;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
	{
		char t[12];
		scanf("%s",t);
		int len = strlen(t);
		for(int j = 1; j <= 10; ++j)
		{
			if(j > len) ch[i][j] = 'a'-1;
			else ch[i][j] = t[j-1];
		}
	}
	solution();
	return 0;
}

