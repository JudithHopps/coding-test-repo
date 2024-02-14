#include <bits/stdc++.h>
using namespace std;

int n, r, c, cnt = -1, ret, siz;

void go(int siz, int y, int x)
{
    if (siz == 1)
    {
        cnt++;
        if (y == r && x == c)
        {
            ret = cnt;
        }
        return;
    }
    int next = siz / 2;

    int xr = (x + next <= c && c < x + siz) ? 1 : 0;
    int yr = (y + next <= r && r < y + siz) ? 1 : 0;
    int mul = yr << 1 | xr;

    cnt += mul * next * next;
    go(next, y + yr * next, x + xr * next);
}

int main()
{
    cin >> n >> r >> c;

    siz = 1 << n;

    go(siz, 0, 0);

    cout << ret << "\n";
    return 0;
}
