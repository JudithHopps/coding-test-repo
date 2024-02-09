#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define time tttt

int a[10004], n, m;
ll time, l = 1, r = 60 * 10000000004, ret;

bool check(ll mid)
{
    ll sum = m;
    for (int i = 0; i < m; i++)
    {
        sum += mid / a[i];
    }
    return sum >= n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    if (n <= m)
    {
        cout << n << "\n";
        return 0;
    }

    while (l <= r)
    {
        ll mid = (l + r) / (1LL * 2);
        if (check(mid))
        {
            time = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    // cout << time << "\n";

    int cnt = n - m;

    time--;

    for (int i = 0; i < m; i++)
    {
        cnt -= (time / a[i]);
    }
    time++;
    for (int i = 0; i < m; i++)
    {
        cnt -= (time % a[i] == 0 ? 1 : 0);

        if (cnt == 0)
        {
            ret = i + 1;
            break;
        }
    }
    // cout << cnt << "\n";
    cout << ret << "\n";

    return 0;
}