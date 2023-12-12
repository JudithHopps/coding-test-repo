#include <bits/stdc++.h>
using namespace std;
int n, ret, l, h, sum;
vector<int> v;

bool ch(int i)
{
    for (int j = 2; j * j <= i; j++)
    {
        if (i % j == 0)
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
    for (int i = 2; i <= n; i++)
    {
        if (ch(i))
            v.push_back(i);
    }

    while (true)
    {
        if (sum >= n)
        {
            sum -= v[l++];
        }
        else if (h == v.size())
        {
            break;
        }
        else
        {
            sum += v[h++];
        }
        if (sum == n)
            ret++;
    }

    cout << ret << "\n";
    return 0;
}