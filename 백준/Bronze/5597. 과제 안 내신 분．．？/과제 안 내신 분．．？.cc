#include <bits/stdc++.h>
using namespace std;
int a[34], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 28; i++)
    {
        cin >> n;
        a[n]++;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (a[i] != 0)
            continue;
        cout << i << "\n";
    }

    return 0;
}