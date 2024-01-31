#include <bits/stdc++.h>
using namespace std;
const int n = 9;
int a[10];
vector<int> ret;

void go(int idx, vector<int> v, int sum)
{
    if (v.size() == 7)
    {
        if (sum == 100)
            ret = v;
        return;
    }
    for (int i = idx + 1; i < n; i++)
    {
        v.push_back(a[i]);
        go(i, v, sum + a[i]);
        v.pop_back();
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    go(-1, {}, 0);

    for (int vv : ret)
    {
        cout << vv << "\n";
    }
    return 0;
}