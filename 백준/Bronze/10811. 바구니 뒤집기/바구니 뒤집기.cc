#include <bits/stdc++.h>
using namespace std;
int n, m, a[104], s, e;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        for (int j = 0; j <= (e - s) / 2; j++)
        {
            swap(a[s + j], a[e - j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
