#include <bits/stdc++.h>
using namespace std;
const int n = 42;
int visited[44], num, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 19; i++)
    {
        cin >> num;
        if (visited[num % n] == 0)
            cnt++;
        visited[num % n]++;
    }

    cout << cnt << "\n";
    return 0;
}