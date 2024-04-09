
#include <iostream>
using namespace std;
const int MOD = 15746;
int n,dp[1000004];

int main()
{
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) ;
	}
	cout << dp[n] % MOD << "\n";
	return 0;
}
