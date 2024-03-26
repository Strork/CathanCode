#include<bits/stdc++.h>
#define oo 0x7f7f7f7f
#define ll long long
#define reg register int

struct treap_Node{
	int size, weight, val, fix;
	int l, r;
}treap[100100];

int tot = 0;
int leave = 0;
int num = 0;
int n, low;
int delta = 0;
int root = 0;
int cost = 0;

inline int read() {
	char ch = getchar();
	int k = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k * f;
}

inline int lsize(int p) {
	return treap[p].l ? treap[treap[p].l].size : 0;
}

inline int rsize(int p) {
	return treap[p].r ? treap[treap[p].r].size : 0;
}

void left_rotate(int &a) {
	int b = treap[a].r;
	treap[a].r = treap[b].l;
	treap[b].l = a;
	a = b;
	b = treap[a].l;
	treap[b].size = lsize(b) + rsize(b) + treap[b].weight;
	treap[a].size = lsize(a) + rsize(a) + treap[a].weight;
}

void right_rotate(int &a) {
	int b = treap[a].l;
	treap[a].l = treap[b].r;
	treap[b].r = a;
	a = b;
	b = treap[a].r;
	treap[b].size = lsize(b) + rsize(b) + treap[b].weight;
	treap[a].size = lsize(a) + rsize(a) + treap[a].weight;
}

void treap_insert(int &p, int val) {
	if (!p) {
		p = ++tot;
		treap[p].size = 1;
		treap[p].weight = 1;
		treap[p].val = val;
		treap[p].fix = rand();
		return;
	}
	++treap[p].size;
	if (val > treap[p].val) {
		treap_insert(treap[p].l, val);
		if (treap[treap[p].l].fix < treap[p].fix)
			right_rotate(p);
	}
	else if (val < treap[p].val) {
		treap_insert(treap[p].r, val);
		if (treap[treap[p].r].fix < treap[p].fix)
			left_rotate(p);
	}
	else {
		++treap[p].weight;
	}
}

int treap_delete(int &p, int val) {
	int temp = 0;
	if (!p) return 0;
	if (treap[p].val < val) {
		temp = treap[treap[p].r].size + treap[p].weight;
		p = treap[p].l;
		return temp + treap_delete(p, val);
	}
	else {
		temp = treap_delete(treap[p].r, val);
		treap[p].size -= temp;
		return temp;
	}
}

int find_kth(int p, int k) {
	if (k < lsize(p) + 1) return find_kth(treap[p].l, k);
	else if (k > lsize(p) + treap[p].weight)
		return find_kth(treap[p].r, k - (treap[p].weight + lsize(p)));
	else return treap[p].val;
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	srand((unsigned)time(NULL));
	n = read(), low = read();
	for (reg i = 1; i <= n; ++i) {
		char ch = getchar();
		int k = read();
		if (ch == 'I') {
			if (k < low) continue;
			++num;
			treap_insert(root, k - delta);
		}
		else if (ch == 'A') delta += k;
		else if (ch == 'S') {
			delta -= k;
			int temp = treap_delete(root, low - delta);
			leave += temp;
			num -= temp;
		}
		else {
			if (k > num) printf("-1\n");
			else {
				int temp = find_kth(root, k);
				printf("%d\n", temp + delta);
			}
		}
	}
	printf("%d\n", leave);
	return 0;
}
