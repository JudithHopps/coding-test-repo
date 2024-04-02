
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
const int MOD = 1000000;
const int P = 15 * (MOD /10);
int dp[P+4];
// 주기는 15*(MOD/10)
int f(int n) {
	if (n <= 1) return n;
	if (dp[n]) return dp[n];
	return (f(n - 1) + f(n - 2))%MOD;
}
void init() {
	for (int i = 0; i <= P; i++) {
		dp[i] = f(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	if (n <= 1) cout << n << "\n";
	else {
		init();
		cout << dp[n%P] << "\n";
	}
	return 0;
}
