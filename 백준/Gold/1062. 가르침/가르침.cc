#include <bits/stdc++.h>
using namespace std;
int n, k, ret, a[54];
string s;

int count(int mask)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & mask) == a[i])
        {
            cnt++;
        }
    }
    return cnt;
}

int go(int idx, int m, int cnt)
{
    if (cnt > k)
        return 0;
    if (idx == 26)
    {
        return count(m);
    }
    int ret = go(idx + 1, m | (1 << idx), cnt + 1);
    if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a')
    {
        ret = max(ret, go(idx + 1, m, cnt));
    }
    return ret;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char c : s)
        {
            a[i] |= (1 << (c - 'a'));
        }
    }
    cout << go(0, 0, 0) << "\n";

    return 0;
}