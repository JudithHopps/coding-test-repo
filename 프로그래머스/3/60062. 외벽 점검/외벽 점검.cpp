#include <bits/stdc++.h>
using namespace std;

int dp[8][1 << 16];
const int INF = 987654321;
vector<int> w, d;
int N,ret;

int go(int idx, int visited) {
    if (visited == (1 << w.size()) - 1) return 0;
    if (idx == d.size()) return INF;

    int& ret = dp[idx][visited];
    if (ret != -1) return ret;
    ret = INF;

    for(int i=0;i<w.size();i++){
        if ((visited & 1 << i)) continue;
        int temp = visited;
        for(int j=0;j<w.size();j++) {
            int diff = (w[j] - w[i] + N) % N;
            if (diff <= d[idx])
                temp |= 1 << j;
        }
        ret = min(ret, go(idx + 1, temp) + 1);
    }
    

    return ret;
}


int solution(int n, vector<int> weak, vector<int> dist) {
    w = weak;
    d = dist;
    N = n;

    sort(d.rbegin(), d.rend());
    memset(dp, -1, sizeof(dp));

    ret = go(0, 0);

    return (ret==INF ? -1 : ret) ;
}