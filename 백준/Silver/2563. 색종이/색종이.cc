#include <bits/stdc++.h>
using namespace std;
int visited[104][104], n, a, b, ret;

int main()
{
    cin >> n;

    for (int k = 0; k < n; k++)
    {
        cin >> a >> b;
        for (int i = a; i < a + 10; i++)
        {
            for (int j = b; j < b + 10; j++)
            {
                visited[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (visited[i][j])
                ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}