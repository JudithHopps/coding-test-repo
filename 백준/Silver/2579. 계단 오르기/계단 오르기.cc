#include<iostream>
#include<algorithm>
using namespace std;

int dp[301];
int stair[301];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++)
	{
		int a = dp[i - 2];
		int b = dp[i - 3] + stair[i - 1] ;
		dp[i] = max(a, b) + stair[i];
	}
	cout << dp[n]<<"\n";
	return 0;
}