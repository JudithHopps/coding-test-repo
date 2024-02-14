#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret, dp[5004];

int main()
{

    cin >> n;

    fill(&dp[0], &dp[0] + 5004, INF);
    dp[3] = 1;
    dp[5] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i + 3] = min(dp[i + 3], dp[i] + 1);
        dp[i + 5] = min(dp[i + 5], dp[i] + 1);
    }

    cout << (dp[n] == INF ? -1 : dp[n]) << "\n";
    return 0;
}