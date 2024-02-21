#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[24], ret = INF;
string s;

void check()
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        int now = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & (1 << j))
                continue;
            now++;
        }
        sum += min(n - now, now);
    }

    ret = min(ret, sum);
}
void go(int idx)
{
    if (idx == n)
    {
        check();
        return;
    }
    go(idx + 1);
    a[idx] = ~a[idx];
    go(idx + 1);
    return;
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
        int k = (1 << (n - 1));
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'H')
            {
                a[i] |= k;
            }
            k /= 2;
        }
    }

    go(0);

    cout << ret << "\n";

    return 0;
}