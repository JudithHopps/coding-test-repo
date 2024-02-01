#include <bits/stdc++.h>
using namespace std;
int n, ret, l, r, sum;
bool visited[4000004];
vector<int> v;

void go(int n)
{
    memset(visited, true, sizeof(visited));
    visited[0] = false, visited[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (visited[i])
        {
            for (int j = 2; i * j <= n; j++)
            {
                visited[i * j] = false;
            }
        }
    }
}
bool check(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    go(n);
    for (int i = 2; i <= n; i++)
    {
        if (visited[i])
        {
            v.push_back(i);
        }
    }

    while (true)
    {
        if (sum >= n)
        {
            sum -= v[l++];
        }
        else if (r == v.size())
        {
            break;
        }
        else
        {
            sum += v[r++];
        }

        if (sum == n)
        {
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}