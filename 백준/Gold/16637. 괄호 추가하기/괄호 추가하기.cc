#include <bits/stdc++.h>
using namespace std;
int n, ret = -987654321, a[20];
char b[20];

int cal(int a, char b, int c)
{
    if (b == '+')
        return a + c;
    if (b == '*')
        return a * c;

    return a - c;
}
void go(int idx, int sum)
{
    if (idx >= n / 2)
    {
        ret = max(ret, sum);
        return;
    }

    // 괄호 X
    go(idx + 1, cal(sum, b[idx], a[idx + 1]));

    // 괄호 O
    int next = cal(a[idx + 1], b[idx + 1], a[idx + 2]);
    go(idx + 2, cal(sum, b[idx], next));

    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%1d%c", &a[i], &b[i]);
        // printf("%d %c \n", a[i], b[i]);
    }
    scanf("%1d", &a[n / 2]);
    // printf("%d\n", a[n / 2]);

    go(0, a[0]);
    printf("%d\n", ret);

    return 0;
}