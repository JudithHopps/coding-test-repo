#include <bits/stdc++.h>
using namespace std;
int n;
char a[10];
vector<string> v;

void go(int idx, int visited, string str)
{
    if (idx == n)
    {
        v.push_back(str);
        return;
    }
    int s, e;
    if (a[idx] == '<')
    {
        s = str.back() - '0' + 1;
        e = 10;
    }
    else
    {
        s = 0;
        e = str.back() - '0';
    }
    for (int i = s; i < e; i++)
    {
        if (visited & (1 << i))
            continue;
        go(idx + 1, visited | (1 << i), str + to_string(i));
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
        cin >> a[i];

    for (int i = 0; i < 10; i++)
    {
        go(0, (1 << i), to_string(i));
    }

    sort(v.begin(), v.end());

    cout << v[v.size() - 1] << "\n"
         << v[0] << "\n";
    return 0;
}