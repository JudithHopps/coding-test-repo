#include <bits/stdc++.h>
using namespace std;
int n, a[70][70];
string ret;

string go(int y, int x, int size)
{
    if (size == 1)
    {
        return to_string(a[y][x]);
    }

    int now = a[y][x];
    bool flag = true;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (a[i][j] != now)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }

    if (flag)
        return to_string(a[y][x]);

    int newSize = size / 2;
    string ret = "";
    ret += "(";
    ret += go(y, x, newSize);
    ret += go(y, x + newSize, newSize);
    ret += go(y + newSize, x, newSize);
    ret += go(y + newSize, x + newSize, newSize);
    ret += ")";
    return ret;
}
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    cout << go(0, 0, n) << "\n";
    return 0;
}