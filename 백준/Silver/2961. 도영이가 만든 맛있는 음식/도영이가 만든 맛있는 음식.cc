#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, ret = 3000000000;
vector<vector<ll>> taste;

void go(vector<int> v)
{
    ll sum1 = 0, sum2 = 0;
    for (int vv : v)
    {
        sum1 += taste[vv][0];
        sum2 += taste[vv][1];
    }
    ret = min(ret, abs(sum1 - sum2));
    return;
}
void combi(int start, vector<int> v)
{
    if (start == n)
    {
        go(v);
    }
    for (int i = start + 1; i < n; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
void goBit()
{
    for (int i = 1; i < (1 << n); i++)
    {
        ll sum1 = 0, sum2 = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                if (sum1 == 0)
                {
                    sum1 = taste[j][0];
                }
                else
                {
                    sum1 *= taste[j][0];
                }
                sum2 += taste[j][1];
            }
        }
        ret = min(ret, abs(sum1 - sum2));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        taste.push_back({a, b});
    }

    // combi
    // combi(-1, {});
    goBit();

    cout << ret << "\n";
    return 0;
}