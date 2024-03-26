#include<bits/stdc++.h>
#define ll long long
#define INF 2100000000
using namespace std;
int n,m;
struct qaq
{
	int y,v,nt;
}e[6001000];
int lin[1000100];
int rev[6001000];
int q[1000100];
int level[1000100];
int len = 0;
int head,tail;

int read()
{
	int k = 0;
	int f = 1;
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

bool make_level()
{
	memset(level,-1,sizeof(level));
	level[1] = 0;
	q[1] = 1;
	head = 0;
	tail = 1;
	while(head++ < tail)
	{
		int x = q[head];
		for(int i = lin[x]; i; i = e[i].nt)
		{
			if(e[i].v && level[e[i].y] == -1)
			{
				q[++tail] = e[i].y;
				level[e[i].y] = level[x] + 1;
			}
		}
	}
	return level[n*m] >= 0;
}

int max_flow(int k,int flow)
{
	if(k == n*m) return flow;
	int maxflow = 0;
	int d = 0;
	for(int i = lin[k]; i && (maxflow < flow); i = e[i].nt)
	{
		if(level[e[i].y] == level[k] + 1 && e[i].v)
		{
		
			if(d = max_flow(e[i].y,min(flow - maxflow,e[i].v)))
			{
				maxflow += d;
				e[i].v -= d;
				e[rev[i]].v += d;
			}
		}
	}
	if(!maxflow) level[k] = -1;
	return maxflow;
}

void dinic()
{
	int ans = 0;
	int d = 0;
	while(make_level())
		while(d = max_flow(1,INF))
			ans += d;
	cout<<ans<<endl;
}

void insert(int x,int y,int v)
{
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].v = v;
	e[len].y = y;
	rev[len] = len + 1;
	e[++len].nt = lin[y];
	lin[y] = len;
	e[len].v = v;
	e[len].y = x;
	rev[len] = len - 1;
}

int main()
{
	//freopen("1001.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			int v = read();
			int x = (i-1) * m + j;
			int y = x + 1;
			insert(x,y,v);
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int v = read();
			int x = (i-1) * m + j;
			int y = x + m;
			insert(x,y,v);
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			int v = read();
			int x = (i-1) * m + j;
			int y = x + m + 1;
			insert(x,y,v);
		}
	}
	dinic();
	return 0;
}
