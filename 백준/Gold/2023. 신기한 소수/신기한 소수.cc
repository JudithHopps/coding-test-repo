#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v1 = {1, 2, 3, 5, 7, 9};
vector<int> v2 = {2, 3, 5, 7, 9};

bool check(int num)
{
    if (num < 2)
        return false;
    if (num != 2 && num % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void go(int idx, int now)
{
    if (!check(now))
        return;
    if (idx == n)
    {
        cout << now << "\n";
        return;
    }

    for (int vv : v1)
    {
        int newNow = now * 10 + vv;
        if (!check(newNow))
            continue;

        go(idx + 1, newNow);
    }
    return;
}

int main()
{
    cin >> n;
    for (int vv : v2)
    {
        go(1, vv);
    }

    return 0;
}
