#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define cl(x) memset(x, 0, sizeof(x))
#define nu NULL

struct node{
	int v;
	int weight;
	int size;
	node *fa;
	node *son[2];
};
node *root = nu;
int n;

inline int read() {
	int k = 0, f = 1;
	char ch = getchar();
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

inline void point(node *p, node *x ) {
	p->v = 
}

inline bool relation(node *p, node *x) {
	return p->son[1] == x;
}

inline void ins(node *x, node *y, bool a) {
	x->son[a] = y;
	if (y != nu) y->fa = x;
}

inline int maintain(node *p) {
	p->size = p->weight;
	if (p->son[0] != nu) p->size += p->son[0]->size;
	if (p->son[1] != nu) p->size += p->son[1]->size;
}

inline void rotate(node *p) {
	node *f = p->fa;
	node *g = f->fa;
	bool a = relation(f, p);
	ins(g, p, relation(g, f));
	ins(f, p->son[a^1], a);
	ins(p, f, a^1);
	maintain(p);
	maintain(f);
	if (p->fa == nu) root = p;
}

void splay(node *p, node *x) {
	while (p->fa != x) {
		node *f = p->fa;
		node *g = f->fa;
		if (g == x) rotate(p);
		else {
			if (relation(g, f) ^ relation(f, p)) rotate(p);
			else rotate(f);
			rotate(p);
		}
	}
}

node *insert(int val) {
	if (root == nu) {
		root = new node(val, nu);
		return root;
	}
	node *p = root;
	node *last;
	while (p != nu && p->v != val) {
		p->size += 1;
		last = p;
		if (val < p->v) p = p->son[0];
		else p = p->son[1];
	}
	if (p != nu) {
		p->size += 1;
		p->weight += 1;
	}
	else {
		last->son[val > last->v] = new node(val, last);
		p = last->son[val > last->v];
	}
	splay(p, nu);
	return root;
}

node *succ(int val) {
	node *ans = nu, *p = root;
	while (p != nu) {
		if (val >= p->v) p = p->son[1];
		else {
			ans = p;
			p = p->son[0];
		}
	}
	splay(ans, nu);
	return root;
}

node *pre(int val) {
	node *ans = nu, *p = root;
	while (p != nu) {
		if (val <= p->v) p = p->son[0];
		else {
			ans = p;
			p = p->son[1];
		}
	}
	splay(ans, nu);
	return root;
}

node *find(int val) {
	node *p = root;
	while (p != nu && val != p->v) {
		if (val < p->v) p = p->son[0];
		else p = p->son[1];
	}
	if (p != nu) splay(p, nu);
	return p;
}

void del(int val) {
	node *p = find(val);
	if (p != nu) {
		if (p->weight > 1) {
			p->size -= 1;
			p->weight -= 1;
		}
		node *x, *y;
		x = pre(val);
		y = succ(val);
		splay(y, x);
		y->son[0] = nu;
		y->size -= 1;
		x->size -= 1;
	}
}

int getrank(int val) {
	node *p = find(val);
	if (p == nu) {
		p = insert(val);
		int ans = p->son[0]->size;
		del(val);
		return ans;
	}
	return p->son[0]->size;
}

int getkth(int k) {
	node *p = root;
	int sz = 0;
	if (p->son[0] != nu)
		sz += p->son[0]->size;
	while (k < sz || k >= sz + p->weight) {
		if (k < sz) p = p->son[0];
		else {
			k -= sz + p->weight;
			p = p->son[1];
		}
	}
	splay(p, nu);
	return p->v;
}

int main() {
	n = read();
	int temp = insert(0x7fffffff); printf("%d\n", temp);
	insert(0x80000000);
	for (reg i = 1; i <= n; ++i) {
		int opt = read();
		int val = read();
		if (opt == 1) insert(val);
		else if (opt == 2) del(val);
		else if (opt == 3) printf("%d\n",getrank(val));
		else if (opt == 4) printf("%d\n",getkth(val));
		else if (opt == 5) printf("%d\n",pre(val)->v);
		else if (opt == 6) printf("%d\n",succ(val)->v);
	}
	return 0;
}
