#include <bits/stdc++.h>
using namespace std;

int dp[1005][200];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {

    temperature += 50; t1 += 50; t2 += 50;

    fill(&dp[0][0],&dp[0][0]+1005*200,INT_MAX);
    
    dp[0][temperature] = 0;

    for(int i=0;i<onboard.size();i++) {
        for(int j=10;j<=100;j++) {
            if(onboard[i] && (j < t1 || t2 < j)) continue;
            if(dp[i][j] >= 1e9) continue;
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (temperature > j ? 0 : a));
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (temperature == j? 0 : b));
            dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + (temperature < j? 0 : a));
        }
    }

    int answer = INT_MAX;
    for(int i=1;i<=100;i++) answer = min(answer, dp[onboard.size()][i]);

    return answer;
}