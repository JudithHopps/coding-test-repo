#include <bits/stdc++.h>
using namespace std;
int a[6], n, ret = 987654321, visited[64][64][64];
struct A
{
    int a, b, c;
};
int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}};

void bfs(int a, int b, int c)
{
    visited[a][b][c] = 1;
    queue<A> q;
    q.push({a, b, c});

    while (q.size())
    {
        if (visited[0][0][0])
            break;

        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);

            if (visited[na][nb][nc])
                continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bfs(a[0], a[1], a[2]);

    cout << visited[0][0][0] - 1 << "\n";

    return 0;
}