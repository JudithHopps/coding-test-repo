
#include <iostream>
using namespace std;
int t, n;
long long dp[104];

void init() {
	dp[0] = 0;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
