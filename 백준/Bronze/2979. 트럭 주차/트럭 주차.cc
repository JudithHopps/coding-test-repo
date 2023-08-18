#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int s, e, sum;
int result[100];

int main()
{
        cin >> a >> b >> c;
        for (int i = 0; i < 3; i++)
        {
                scanf("%d %d", &s, &e);

                for (int j = s; j < e; j++)
                {
                        result[j]++;
                }
        }
        for (int i = 0; i < 100; i++)
        {
            sum += a * (result[i] == 1) + b * 2 * (result[i] == 2) + c * 3 * (result[i] == 3);
        }

        cout << sum << "\n";

        return 0;
}