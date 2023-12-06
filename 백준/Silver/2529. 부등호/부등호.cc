#include <bits/stdc++.h>
using namespace std;
int n;
char a[10];
vector<string> ret;

void go(int idx, string s, int visited)
{
    if (idx == n)
    {
        ret.push_back(s);
        return;
    }
    char before = s[idx] - '0';

    if (a[idx] == '<')
    {
        for (int i = before + 1; i < 10; i++)
        {
            if (visited & (1 << i))
                continue;
            go(idx + 1, s + to_string(i), visited | (1 << i));
        }
    }
    else
    {
        for (int i = 0; i < before; i++)
        {
            if (visited & (1 << i))
                continue;
            go(idx + 1, s + to_string(i), visited | (1 << i));
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

    for (int i = 0; i < 10; i++)
    {
        go(0, to_string(i), 1 << (i));
    }
    sort(ret.begin(), ret.end());

    cout
        << ret[ret.size() - 1] << "\n"
        << ret[0] << "\n";

    return 0;
}