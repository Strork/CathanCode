#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("a.in" , "r", stdin);
    freopen ("a.out", "w", stdout);
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		bool if_k = 0, if_m = 0;
		int lengthn = tmp.length();
		int space_index1 = -1;
		int space_index3 = -1;
		int cnt = 0;
		for (int j = 0; j < lengthn; j++)
		{
			if (tmp[j] == 'k')
			{
				if_k = 1;
			}
			if (tmp[j] == ' ')
			{
				cnt++;
				if (cnt == 1)
				{
					space_index1 = j;
				}
				if (cnt == 3)
				{
					space_index3 = j;
				}
			}
		}
		if (tmp[lengthn - 2] == 'm')
		{
			if_m = 1;
		}
		string num1;
		for (int j = 0; j < space_index1; j++)
		{
			num1 += tmp[j];
		}
		string half1;
		for (int j = 0; j <= space_index3; j++)
		{
			half1 += tmp[j];
		}
		string ans;
		ans = half1 + num1;
		if (num1 == "0")
		{
			if (if_m)
			{
				ans += " m";
			}
		}
		else
		{
			if (if_k)
			{
				ans += "000";
			}
			if (if_m)
			{
				ans += "000 m";
			}
			else
			{
				ans += " ";
			}

		}
		ans += tmp[lengthn - 1];
		for (int i = 0; i < ans.length(); ++i) {
            cout << ans[i];
        }
        cout << endl;
	}
	return 0;
}