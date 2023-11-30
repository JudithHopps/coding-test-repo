#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, ret, visited[10004];
vector<int> adj[10004], v;
map<int, int> mp;

int dfs(int here)
{
    if (visited[here])
        return 0;
    visited[here] = 1;
    int cnt = 1;

    for (int there : adj[here])
    {
        if (visited[there])
            continue;
        cnt += dfs(there);
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        mp[i] = dfs(i);
        ret = max(ret, mp[i]);
    }

    for (auto it : mp)
    {
        if (it.second == ret)
        {
            v.push_back(it.first);
        }
    }

    for (int vv : v)
    {
        cout << vv << " ";
    }
    return 0;
}