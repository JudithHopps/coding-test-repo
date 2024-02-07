#include <stdio.h>

int N, K;
int tree[262144];
int start, leafSize;

void update(int index, int diff)
{
    index += start;

    while (index > 1)
    {
        tree[index] += diff;
        index /= 2;
    }
}

int getNumber(int index)
{
    int treeIdx = 1;
    while (treeIdx < leafSize)
    {
        if (index <= tree[treeIdx * 2])
            treeIdx *= 2;
        else
        {
            index -= tree[treeIdx * 2];
            treeIdx = treeIdx * 2 + 1;
        }
    }

    return treeIdx - start;
}

int main()
{
    scanf("%d %d", &N, &K);

    for (leafSize = 1; leafSize <= N; leafSize <<= 1)
        ;
    start = leafSize - 1;

    for (int i = 1; i <= N; i++)
        update(i, 1);

    int index, remain;

    index = K, remain = N;

    printf("<");
    for (int i = 1; i <= N - 1; i++)
    {
        int number = getNumber(index);

        printf("%d, ", number);

        update(number, -1);

        index = index - 1 + K;
        remain = remain - 1;
        index = (index - 1) % remain + 1;
    }

    printf("%d>\n", getNumber(1));

    return 0;
}