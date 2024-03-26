#include<bits/stdc++.h>
using namespace std;
int hh, mm;
int val, a;
int cost, b;

void solution() {
	double ans = 0.0;
	int cnt;
	if (hh < 20) {
		cnt = val / b;
		if (val % b != 0) cnt++;
		ans = 1.0 * cnt * cost;
		int tim = (19 - hh) * 60 + (60 - mm);
		val += tim * a;
		cnt = val / b;
		if (val % b != 0) cnt++;
		double temp = 0.8 * cnt * cost;
		if (temp < ans) ans = temp;
		printf("%.4lf", ans);
	}
	else {
		cnt = val / b;
		if (val % b != 0) cnt++;
		ans = 0.8 * cnt * cost;
		printf("%.4lf", ans);
	}
}

int main() {
	scanf("%d%d", &hh, &mm);
	scanf("%d%d%d%d", &val, &a, &cost, &b);
	solution();
	return 0;
}
