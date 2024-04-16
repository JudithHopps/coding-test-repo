#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
string a, b;
int dp[1004][1004];
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	// DP
	int n = a.size(), m = b.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m] << "\n";


	// lcs 찾기
	int i = n, j = m;
	string ret = "";
	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			ret += a[i-1];
			i--, j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
	reverse(ret.begin(), ret.end());
	cout << ret << "\n";
	return 0;
}
