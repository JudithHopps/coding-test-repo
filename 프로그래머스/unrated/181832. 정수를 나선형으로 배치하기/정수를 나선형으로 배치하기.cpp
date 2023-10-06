#include <string>
#include <vector>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0)); // Initialize answer as an n x n matrix filled with 0s

    int y = 0, x = 0, dir = 0;

    for (int i = 1; i <= n * n; i++) {
        answer[y][x] = i;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || answer[ny][nx] != 0) {
            // Change direction when hitting boundaries or already filled cell
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        y = ny;
        x = nx;
    }

    return answer;
}
