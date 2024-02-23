#include <bits/stdc++.h>
using namespace std;
int n, s, e, ret = 1;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());

    int start = v[0].second;
    int end = v[0].first;

    for (int i = 1; i < n; i++)
    {
        if (end <= v[i].second)
        {
            ret++;
            start = v[i].second;
            end = v[i].first;
        }
    }

    cout << ret << "\n";
    return 0;
}