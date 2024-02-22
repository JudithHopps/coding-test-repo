#include <bits/stdc++.h>
using namespace std;
int r, c, ret = 0;
char a[24][24];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int v(int y, int x)
{
    return a[y][x] - 'A';
}
void go(int y, int x, int visited, int cnt)
{
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
            continue;
        if (visited & (1 << v(ny, nx)))
            continue;
        go(ny, nx, visited | (1 << v(ny, nx)), cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    go(0, 0, 1 << v(0, 0), 1);

    cout << ret << "\n";

    return 0;
}