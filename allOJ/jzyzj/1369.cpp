#include<bits/stdc++.h>
using namespace std;
char str[300010];
int n;
int m;
char s[5010];
struct qaq{
	bool end;
	int fail;
	int lin[26];
	int deep;
}trie[1600100];
int len = 0;
int slen = 0;
int head, tail;
int q[1600100];
bool f[30][30][30][30];
int ans = 0;
int l, r;
struct qwq{
	int st,ed;
}a[300100];
bool vis[300100];
int id = 0;

void add_node(int k, int node){
	char ch = s[k] - 'a';
	if(!trie[node].lin[ch]){
		trie[node].lin[ch] = ++len;
		trie[len].fail = 0;
		trie[len].deep = trie[node].deep + 1;
		trie[len].end = 0;
	}
	int nt = trie[node].lin[ch];
	if(k == slen){
		trie[nt].end = 1;
		return;
	}
	add_node(k+1, nt);
}

void build_fail(){
	head = tail = 0;
	q[tail] = 0;
	while(head <= tail){
		int node = q[head++];
		int temp;
		for(int i = 0; i < 26; ++i){
			if(trie[node].lin[i]){
				int nt = trie[node].lin[i];
				if(node){
					temp = trie[node].fail;
					while(!trie[temp].lin[i] && temp)
						temp = trie[temp].fail;
					trie[nt].fail = trie[temp].lin[i];
				}
				q[++tail] = nt;
			}
		}
	}
}

void find(){
	id = 0;
	int node = 0;
	for(int i = 1; i <= n; ++i){
		char ch = str[i] - 'a';
		while(!trie[node].lin[ch] && node)
			node = trie[node].fail;
		node = trie[node].lin[ch];
		int temp = node;
		while(temp){
			if(trie[temp].end){
				if(a[id].ed != i){
					a[++id].st = i - trie[temp].deep + 1;
					a[id].ed = i;
				}
				else a[id].st = min(a[id].st, i - trie[temp].deep + 1);
			}
			temp = trie[temp].fail;
		}
	}
}

bool mycmp(qwq x, qwq y){
	if(x.st == y.st) return x.ed > y.ed;
	else return x.st < y.st;
}
void solution(){
	sort(a+1, a+1+id, mycmp);
	memset(vis,0,sizeof(vis));
	for(int i = 1; i <= id; ++i){
		if(vis[a[i].ed]) continue;
		for(int j = a[i].st; j <= a[i].ed; ++j) vis[j] = 1;
	}
	ans = n;
	for(int i = 1; i <= n; ++i) if(vis[i]) --ans;
	printf("%d\n",ans);
}

int main(){
	//freopen("a.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i = 1; i <= n-3; ++i)
		f[str[i] - 'a'][str[i+1] - 'a'][str[i+2] - 'a'][str[i+3] - 'a'] = 1;
	scanf("%d",&m);
	for(int i = 1; i <= m; ++i){
		scanf("%s",s+1);
		slen = strlen(s+1);
		if(slen > n) continue;
		bool flag = 1;
		for(int j = 1; j <= slen - 3; ++j)
			if(!f[s[j] - 'a'][s[j+1] - 'a'][s[j+2] - 'a'][s[j+3] - 'a']){
				flag = 0;
				break;
			}
		if(flag) add_node(1, 0);
	}
	build_fail();
	find();
	solution();
	return 0;
}
