#include <bits/stdc++.h>
using namespace std;
int n, a[24], ret = 987654321;
string s;

void go(int cur)
{
    if (cur == n)
    {
        int sum = 0;
        for (int i = 1; i < (1 << n); i *= 2)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] & i)
                {
                    cnt++;
                }
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(cur + 1);
    a[cur] = ~a[cur];
    go(cur + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int v = 1;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'T')
            {
                a[i] |= v;
            }
            v *= 2;
        }
    }

    go(0);

    cout << ret << "\n";
    return 0;
}