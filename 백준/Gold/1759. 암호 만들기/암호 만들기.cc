#include <bits/stdc++.h>
using namespace std;
int l, n, m;
char c;
map<int, int> mp, moum;
vector<string> v;

bool check(string str)
{
    bool flag = false;
    int cnt = 0;

    for (char c : str)
    {
        if (moum[c])
            flag = true;
        else
            cnt++;
    }

    return flag && cnt >= 2 ? true : false;
}
void go(int idx, string str, int visited)
{
    // cout << str << "\n";

    if (str.size() == n)
    {
        if (check(str))
            v.push_back(str);
        return;
    }

    for (int i = str.back() + 1; i <= 'z'; i++)
    {
        if (visited & 1 << (i - 'a'))
            continue;
        if (mp[i] == 0)
            continue;
        go(idx + 1, str + (char)i, visited | (1 << (i - 'a')));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (char c : "aeiou")
    {
        moum[c] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> c;
        mp[c] = 1;
    }
    string s = "";
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (mp[i] == 0)
            continue;
        // cout << s + (char)i << "\n";
        go(0, s + (char)i, 1 << (i - 'a'));
    }

    sort(v.begin(), v.end());

    for (string s : v)
    {
        cout << s << "\n";
    }
    return 0;
}