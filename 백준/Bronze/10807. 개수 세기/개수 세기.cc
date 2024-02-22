#include <bits/stdc++.h>
using namespace std;
int n, num, cnt[204], m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cnt[num + 100]++;
    }
    cin >> num;
    cout << cnt[num + 100] << "\n";

    return 0;
}