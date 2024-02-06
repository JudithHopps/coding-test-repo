#include <bits/stdc++.h>
using namespace std;
int n, m, r, a[304][304], b[304][304];
int dir = 0;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void rot()
{
    for (int k = 0; k < min(n, m) / 2; k++)
    {
        dir = 0;
        int temp = a[k][k];
        int y = k, x = k;
        while (dir < 4)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < k || nx < k || ny >= n - k || nx >= m - k)
            {
                dir++;
                continue;
            }
            a[y][x] = a[ny][nx];
            y = ny;
            x = nx;
        }
        a[k + 1][k] = temp;
    }
}
int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    while (r--)
    {
        rot();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}