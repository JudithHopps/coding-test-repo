#include <bits/stdc++.h>
using namespace std;
string str;
bool flag = false;
int r, c, ret, visited[10004][504];
char a[10004][504];
const int dy[] = {-1, 0, 1};
const int dx[] = {1, 1, 1};

// 근처 빵집 가스관

//   ==  // \\ 

// 원웅이의 빵집

void dfs(int y, int x)
{
    if (x == c - 1)
    {
        flag = true;
        ret++;
        return;
    }

    for (int dir = 0; dir < 3; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == 'x')
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
        if (flag)
            return;
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> str;
        for (int j = 0; j < c; j++)
            a[i][j] = str[j];
    }

    for (int i = 0; i < r; i++)
    {
        dfs(i, 0);
        flag = false;
    }

    cout << ret << "\n";

    return 0;
}