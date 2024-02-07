#include <bits/stdc++.h>
using namespace std;
int S[54], I[54], P[54], n, visited[54], dp[1004][1004];

int go(int STR, int INT)
{
    int &ret = dp[STR][INT];
    if (ret != -1)
        return ret;
    ret = 0;
    int p = 0;
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (S[i] <= STR || I[i] <= INT)
        {
            ret++;
            if (!visited[i])
            {
                p += P[i];
                visited[i] = 1;
                temp.push_back(i);
            }
        }
    }

    for (int i = 0; i <= p; i++)
    {
        int nextSTR = min(1000, STR + i);
        int nextINT = min(1000, INT + p - i);
        ret = max(ret, go(nextSTR, nextINT));
    }

    for (int tt : temp)
    {
        visited[tt] = 0;
    }
    return ret;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i] >> I[i] >> P[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << go(1, 1) << "\n";

    return 0;
}