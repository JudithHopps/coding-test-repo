#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int basket[101];

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        basket[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        reverse(basket + a, basket + b + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << basket[i] << ' ';
    }

    return 0;
}