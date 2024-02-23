#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 101
#define MAX_M 101
#define MAX_LANDS 1001

int N, M;
int board[MAX_N][MAX_M];
int weights[MAX_LANDS][MAX_LANDS];

int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int flag)
{
    board[x][y] = flag;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (board[nx][ny] != 0)
            continue;
        dfs(nx, ny, flag);
    }
}

void find_dist(int x_lim, int y_lim, bool is_row)
{
    for (int i = 0; i < x_lim; ++i)
    {
        int cur = 0;
        int from = -1;
        for (int j = 0; j < y_lim; ++j)
        {
            int land = (is_row) ? board[i][j] : board[j][i];
            if (land > 0)
            {
                if (from == -1)
                {
                    from = land;
                    cur = 0;
                }
                else if (from != land)
                {
                    int min_weight = (weights[from][land] == 0) ? cur : min(cur, weights[from][land]);
                    if (min_weight > 1)
                    {
                        weights[from][land] = min_weight;
                        weights[land][from] = min_weight;
                    }
                    from = land;
                    cur = 0;
                }
                else
                {
                    from = land;
                    cur = 0;
                }
            }
            else if (from != -1)
            {
                ++cur;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            --board[i][j];
        }
    }

    // 섬 구분
    int lands_size = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 0)
            {
                dfs(i, j, lands_size++);
            }
        }
    }

    // 최단 거리 찾기
    find_dist(N, M, true);
    find_dist(M, N, false);

    // MST 산출
    int minEdge[MAX_LANDS];
    bool visited[MAX_LANDS];
    memset(minEdge, 0x3f, sizeof(minEdge));
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    minEdge[1] = 0;
    pq.push({0, 1});

    int answer = 0;
    int c = 0;

    while (!pq.empty())
    {
        auto [weight, no] = pq.top();
        pq.pop();
        if (visited[no])
            continue;

        answer += weight;
        visited[no] = true;

        if (++c == lands_size - 1)
            break;

        for (int i = 1; i < lands_size; ++i)
        {
            if (!visited[i] && weights[no][i] != 0 && weights[no][i] < minEdge[i])
            {
                minEdge[i] = weights[no][i];
                pq.push({minEdge[i], i});
            }
        }
    }

    cout << ((c == lands_size - 1) ? answer : -1) << "\n";

    return 0;
}
