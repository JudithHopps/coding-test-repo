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
                if (result[i] == 1)
                {
                        sum += a;
                }
                else if (result[i] == 2)
                {
                        sum += b * 2;
                }
                else if (result[i] == 3)
                {
                        sum += c * 3;
                }
        }
        cout << sum << "\n";

        return 0;
}