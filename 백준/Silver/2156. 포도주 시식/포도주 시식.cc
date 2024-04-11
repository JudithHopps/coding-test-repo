#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;
int n, dp[10004],a[10004];

int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], dp[i - 3] + a[i - 1] + a[i]);
		dp[i] = max(dp[i], dp[i - 2] + a[i]);
	}

	cout << dp[n] << "\n";
	return 0;
}
