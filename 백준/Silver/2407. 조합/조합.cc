#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
string dp[104][104];
string add(string a, string b)
{
    string ret = "";
    int sum = 0;

    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += ((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string go(int n, int m)
{
    if (m == 0 || m == n)
        return "1";
    string &ret = dp[n][m];
    if (ret != "")
        return ret;
    return ret = add(go(n - 1, m - 1), go(n - 1, m));
}

int main()
{

    cin >> n >> m;

    cout << go(n, m) << "\n";

    return 0;
}