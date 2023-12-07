#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv, ret = 987654321;
struct A
{
    int p, f, s, v, c;
} a[20];
map<int, vector<vector<int>>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
    }

    for (int i = 1; i < (1 << n); i++)
    {
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> temp;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                p += a[j].p;
                f += a[j].f;
                s += a[j].s;
                v += a[j].v;
                c += a[j].c;
                temp.push_back(j + 1);
            }
        }

        if (p >= mp && s >= ms && f >= mf && v >= mv)
        {
            ret = min(ret, c);
            ans[c].push_back(temp);
        }
    }

    if (ret == 987654321)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ret << "\n";
        sort(ans[ret].begin(), ans[ret].end());

        for (int i : ans[ret][0])
        {
            cout << i << " ";
        }
    }

    return 0;
}