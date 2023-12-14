#include <bits/stdc++.h>
using namespace std;
int r, c, t, ret, a[104][104], temp[104][104], flag;
const int dy1[] = {0, -1, 0, 1};
const int dx1[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 0, -1};
const int dx2[] = {1, 0, -1, 0};
vector<pair<int, int>> v1, v2;

void miseGo()
{
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] <= 0)
                continue;
            int mise = a[i][j] / 5;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy1[k];
                int nx = j + dx1[k];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                    continue;
                if (a[ny][nx] == -1)
                    continue;
                temp[i][j] -= mise;
                temp[ny][nx] += mise;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == -1)
                continue;
            a[i][j] = max(a[i][j] + temp[i][j], 0);
            // cout << a[i][j] << " ";
        }
        // cout << "\n";
    }
    return;
}

void clearArr(int i, int j, const int dy[], const int dx[], vector<pair<int, int>> &v)
{
    int y = i, x = j + 1;
    int k = 0;

    while (!(y == i && x == j))
    {
        v.push_back({y, x});
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
        {
            k++;
            ny = y + dy[k];
            nx = x + dx[k];
        }
        y = ny, x = nx;
    }
}

void clearAir()
{
    vector<int> v;
    for (auto it : v1)
    {
        v.push_back(a[it.first][it.second]);
    }
    a[v1[0].first][v1[0].second] = 0;
    for (int i = 1; i < v1.size(); i++)
    {
        a[v1[i].first][v1[i].second] = v[i - 1];
    }

    v.clear();
    for (auto it : v2)
    {
        v.push_back(a[it.first][it.second]);
    }
    a[v2[0].first][v2[0].second] = 0;
    for (int i = 1; i < v2.size(); i++)
    {
        a[v2[i].first][v2[i].second] = v[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1 && flag)
            {
                clearArr(i, j, dy2, dx2, v2);
            }
            if (a[i][j] == -1 && !flag)
            {
                flag = 1;
                clearArr(i, j, dy1, dx1, v1);
            }
        }
    }

    // for (auto it : v2)
    // {
    //     cout << it.first << " , " << it.second << " \n";
    // }
    while (t--)
    {
        miseGo();
        clearAir();
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] > 0)
            {
                ret += a[i][j];
            }
        }
    }

    cout << ret << "\n";

    return 0;
}