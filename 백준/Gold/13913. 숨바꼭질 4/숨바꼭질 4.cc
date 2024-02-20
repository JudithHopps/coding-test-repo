#include <bits/stdc++.h>
using namespace std;
int n, k, visited[100004], pre[100004];
queue<int> q;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    memset(pre, -1, sizeof(pre));

    q.push(n);
    visited[n] = 1;

    while (q.size())
    {
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, now * 2})
        {
            if (next < 0 || next > 100000)
                continue;
            if (visited[next])
                continue;
            visited[next] = visited[now] + 1;
            pre[next] = now;
            q.push(next);
        }
    }

    cout << visited[k] - 1 << "\n";

    for (int i = k; i != -1; i = pre[i])
    {
        v.push_back(i);
    }

    reverse(v.begin(), v.end());

    for (int vv : v)
    {
        cout << vv << " ";
    }
    return 0;
}