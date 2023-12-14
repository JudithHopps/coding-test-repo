#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[24][24], ret = INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++)
    {
        if (__builtin_popcount(i) != n / 2)
            continue;
        vector<int> team1, team2;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                team1.push_back(j);
            }
            else
            {
                team2.push_back(j);
            }
        }

        if (team1.size() == n / 2 && team2.size() == n / 2)
        {
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < n / 2; i++)
            {
                for (int j = i + 1; j < n / 2; j++)
                {
                    sum1 += a[team1[i]][team1[j]];
                    sum1 += a[team1[j]][team1[i]];

                    sum2 += a[team2[i]][team2[j]];
                    sum2 += a[team2[j]][team2[i]];
                }
            }
            ret = min(ret, abs(sum1 - sum2));
            if (ret == 0)
                break;
        }
    }

    cout << ret << "\n";
    return 0;
}