#include <vector>
#include <cstring>
#define MOD 20170805
using namespace std;

int dp[501][501][2], In[501][501], M, N;

int go(int y, int x, int dir)
{
    if (y == M - 1 && x == N - 1)
        return 1;
    if (y > M || x > N)
        return 0;
    if (In[y][x] == 1)
        return 0;

    int &ret = dp[y][x][dir];
    if (ret != -1)
        return ret;
    ret = 0;
    if (In[y][x] == 0)
    {
        ret += go(y + 1, x, 0) % MOD;
        ret += go(y, x + 1, 1) % MOD;
    }
    else if (In[y][x] == 2)
    {
        if (dir == 0)
        {
            ret += go(y + 1, x, 0) % MOD;
        }
        else if (dir == 1)
        {
            ret += go(y, x + 1, 1) % MOD;
        }
    }
    return ret % MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            In[i][j] = city_map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    M = m;
    N = n;
    answer = go(0, 0, 0) % MOD;
    return answer;
}