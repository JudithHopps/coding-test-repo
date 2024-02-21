#include <bits/stdc++.h>
using namespace std;
int k, a[(1 << 10) + 4];
vector<int> tree[14];

void go(int l, int r, int h)
{

    int mid = (l + r) / 2;
    tree[h].push_back(a[mid]);
    if (l == r)
        return;
    go(l, mid - 1, h + 1);
    go(mid + 1, r, h + 1);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int l = 1, r = (1 << k) - 1;
    // cout << r << "\n";
    for (int i = 1; i <= r; i++)
    {

        cin >> a[i];
        // cout << a[i] << " ";
    }

    go(l, r, 0);

    for (int i = 0; i < k; i++)
    {
        for (int vv : tree[i])
        {
            cout << vv << " ";
        }
        cout << "\n";
    }

    return 0;
}