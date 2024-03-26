int f[300100];
int g[300100];
int a[300100];

int binary(int x) {
	int lf = 0, rt = k, mid;
	while (lf + 1 < rt)	{
		mid = ((lf + rt) >> 1);
		if (g[mid] < x) lf = mid;
		else rt = mid;
	}
	if (g[rt] < x) lf = rt;
	return lf;
}

void solution() {
	f[1] = 1;
	g[1] = a[1];
	k = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > g[k]) {
			k++;
			g[k] = a[i];
			f[i] = k;
		}
		else {
			int t = binary(a[i]);
			f[i] = t + 1;
			if (g[t + 1] > a[i]) g[t + 1] = a[i];
		}
	}
	printf("%d\n", k);
}
