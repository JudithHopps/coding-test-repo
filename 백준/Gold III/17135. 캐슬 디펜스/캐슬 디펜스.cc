#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, d, all, ret, a[20][20], b[20][20], visited[20][20];
vector<pair<int, int>> v, now;
void check()
{
    int cnt = 0;
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j])
            {
                temp.push_back({i, j});
                cnt++;
            }
        }
    }
    now = temp;
    return;
}
void move()
{
    if (now.size() == 0)
        return;
    sort(now.begin(), now.end());
    reverse(now.begin(), now.end());
    for (auto it : now)
    {
        b[it.first][it.second] = 0;
        if (it.first + 1 == n)
            continue;
        b[it.first + 1][it.second] = 1;
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void go(vector<int> solder, int cnt)
{

    ret = max(ret, cnt);
    if (now.empty())
        return;
    memset(visited, 0, sizeof(visited));
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        int min = INF;
        int y = n, x = n;
        for (auto it : now)
        {
            int dist = abs(n - it.first) + abs(solder[i] - it.second);
            if (dist > d)
                continue;

            if (min > dist || (min == dist && x > it.second))
            {
                min = dist;
                y = it.first;
                x = it.second;
                // cout << "~~: " << y << " " << x << "\n";
            }
        }
        if (visited[y][x] || min == INF)
            continue;
        visited[y][x] = 1;
        // cout << "babo: " << y << " " << x << "\n";
        b[y][x] = 0;
        sum++;
        // print();
    }

    // cout << sum << "\n";
    check();
    // print();
    move();
    check();
    go(solder, cnt + sum);
    // print();
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                v.push_back({i, j});
                all++;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                // cout << i << " " << j << " " << k << "\n";
                memcpy(b, a, sizeof(b));
                now = v;
                go({i, j, k}, 0);
            }
        }
    }

    cout << ret << "\n";
    return 0;
}