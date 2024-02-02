#include <bits/stdc++.h>
using namespace std;
int n, ret;
deque<int> dq;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (true)
    {
        if (dq.size() == 1)
            break;
        dq.pop_front();
        int now = dq.front();
        dq.pop_front();
        dq.push_back(now);
    }
    cout << dq.front() << "\n";

    return 0;
}