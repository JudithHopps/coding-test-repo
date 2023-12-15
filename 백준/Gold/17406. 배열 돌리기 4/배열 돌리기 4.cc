#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, k, a[54][54], b[54][54], r, c, s, sy, sx, ey, ex, dir, ret = INF;
const int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
int visited[54][54];
struct A
{
    int r, c, s;
};
vector<A> rot;
vector<int> idx, v;
vector<pair<int, int>> pairV;

void go(int y, int x)
{
    if (y == sy && x == ex)
        dir++;
    if (y == ey && x == ex)
        dir++;
    if (y == ey && x == sx)
        dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (visited[ny][nx])
        return;
    visited[ny][nx] = 1;
    pairV.push_back({ny, nx});
    v.push_back(b[ny][nx]);
    go(ny, nx);
    return;
}
void rotateAll(int r, int c, int s)
{
    for (int i = 1; i <= s; i++)
    {
        memset(visited, 0, sizeof(visited));
        pairV.clear();
        v.clear();
        dir = 0;

        sy = r - i;
        sx = c - i;
        ey = r + i;
        ex = c + i;

        visited[sy][sx] = 1;
        pairV.push_back({sy, sx});
        v.push_back(b[sy][sx]);

        go(sy, sx);

        // for (auto it : pairV)
        // {
        //     v.push_back(b[it.first][it.second]);
        // }

        rotate(v.begin(), v.end() - 1, v.end());

        for (int i = 0; i < v.size(); i++)
        {
            b[pairV[i].first][pairV[i].second] = v[i];
        }
    }
    return;
}
void solve()
{
    for (int i : idx)
    {
        rotateAll(rot[i].r, rot[i].c, rot[i].s);
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += b[i][j];
        }
        ret = min(sum, ret);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        r--, c--;
        rot.push_back({r, c, s});
        idx.push_back(i);
    }

    do
    {
        memcpy(b, a, sizeof(b));
        solve();
    } while (next_permutation(idx.begin(), idx.end()));

    cout << ret << "\n";

    return 0;
}