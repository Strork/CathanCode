#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1001000];
int len = 0;
int slen = 0;
struct qaq{
	bool end;
	int fail;
	int lin[26];
	int deep;
}trie[1000];
int q[1000];
int head, tail;
bool f[1001000];

void add_node(int k, int node){
	int ch = s[k] - 'a';
	if(!trie[node].lin[ch]){
		trie[node].lin[ch] = ++len;
		trie[len].end = 0;
		trie[len].fail = 0;
		trie[len].deep = trie[node].deep + 1;
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
	int maxx = 0;
	int node = 0;
	memset(f,0,sizeof(f));
	f[0] = 1;
	for(int i = 1; i <= slen; ++i){
		int ch = s[i] - 'a';
		//cout<<i<<endl;
		//if(!trie[node].lin[ch] && node && !trie[node].end) break;
		while(!trie[node].lin[ch] && node)
			node = trie[node].fail;
		node = trie[node].lin[ch];
		int temp = node;
		while(temp && trie[temp].end){
			if(f[i - trie[temp].deep]){
				f[i] = 1;
				if(i > maxx) maxx = i;
			}
			temp = trie[temp].fail;
		}
	}
	printf("%d\n",maxx);
}

int main(){
	freopen("a.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i){
		scanf("%s",s+1);
		slen = strlen(s+1);
		add_node(1,0);
	}
	build_fail();
	for(int i = 1; i <= m; ++i){
		scanf("%s",s+1);
		slen = strlen(s+1);
		find();
		//for(int i = 1; i <= 20; ++i) cout<<i<<' '<<f[i]<<endl;
	}
	return 0;
}
