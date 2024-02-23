#include <bits/stdc++.h>
using namespace std;
int n, d, k, c, ret = 1, now = 1, cnt[3004], a[6000004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[n + i] = a[i];
    }

    cnt[c]++;

    for (int i = 0; i < k - 1; i++)
    {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1)
            now++;
    }

    for (int start = 0; start < n; start++)
    {
        // cout << start + k << "\n";
        cnt[a[start + k - 1]]++;
        if (a[start + k - 1] != c && cnt[a[start + k - 1]] == 1)
        {
            now++;
        }
        ret = max(ret, now);
        cnt[a[start]]--;
        if (cnt[a[start]] == 0)
            now--;
        // cout << now << " ";
    }
    // cout << "\n";
    cout << ret << "\n";
    return 0;
}