#include<bits/stdc++.h>
using namespace std;

struct qaq
{
	int len;
	int c[500];
}f[120];//0 1 5 16
int n;

qaq mul(qaq a)
{
	for(int i = 1; i <= a.len; i++)
		a.c[i] *= 3;
	for(int i = 1; i <= a.len; i++)
	{
		a.c[i+1] += a.c[i] / 10;
		a.c[i] %= 10;
	}
	while(a.c[a.len+1] != 0) 
	{
		++a.len;
		a.c[a.len+1] += a.c[a.len] / 10;
		a.c[a.len] %= 10;
	}
	while(a.c[a.len] == 0) a.len--;
	return a;
}

qaq sub(qaq a,qaq b)
{
	for(int i = 1; i <= a.len; i++)
	{
		a.c[i] -= b.c[i];
		if(a.c[i] < 0) a.c[i] += 10, a.c[i+1] -= 1;
	}
	while(a.c[a.len] == 0) a.len--;
	return a;
}

qaq big(qaq a,qaq b)
{
	qaq c;
	c = sub(mul(a),b);
	c.c[1] += 2;
	int j = 1;
	while(c.c[j] >= 10)
	{
		c.c[j] -= 10;
		++j;
		c.c[j] += 1; 
	}
	if(c.c[c.len] != 0) c.len++;
	while(c.c[c.len] == 0) c.len--;
	return c;
}

int main()
{
	f[1].len = 1;
	f[1].c[1] = 1;
	f[2].len = 1;
	f[2].c[1] = 5;
	scanf("%d",&n);
	for(int i = 3; i <= n; i++)
		f[i] = big(f[i-1],f[i-2]);
	for(int i = f[n].len; i >= 1; i--)
	{
		printf("%d",f[n].c[i]);
	}
	cout<<endl;
	return 0;
}
