#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
string a, b;
int dp[4004][4004];
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	int ret = 0;
	// DP
	int n = a.size(), m = b.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}

	cout <<ret<< "\n";


	
	return 0;
}
