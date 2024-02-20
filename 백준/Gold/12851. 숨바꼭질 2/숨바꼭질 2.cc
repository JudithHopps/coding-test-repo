#include <bits/stdc++.h>
using namespace std;
int n, k, visited[100004], cnt[100004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;

    while (q.size())
    {
        int now = q.front();
        q.pop();

        for (int next : {now + 1, now - 1, now * 2})
        {
            if (next < 0 || next > 100000)
                continue;
            if (visited[next] == visited[now] + 1)
            {
                cnt[next] += cnt[now];
            }
            else if (!visited[next])
            {
                visited[next] = visited[now] + 1;
                q.push(next);
                cnt[next] += cnt[now];
            }
        }
    }

    cout << visited[k] - 1 << "\n"
         << cnt[k] << "\n";
    return 0;
}