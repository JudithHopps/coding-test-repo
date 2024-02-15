#include <string>
#include <vector>

using namespace std;
const int INF = 987654321;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    //온도 10도 상승
    int T = temperature +10 , T1 = t1+10 , T2 = t2+10;
    int n = onboard.size();
    
    // dp 초기화 
    int dp[1004][54]; 
    fill(&dp[0][0], &dp[0][0] + 1004*54,INF);
    int now = T;
    dp[0][now] = 0; 
    
    for(int i=0;i<n;i++){
        for(int t = 0 ;t <= 50;t++){
            if(dp[i][t] == INF) continue;
            if(onboard[i] && (T1 > t|| T2 < t ) )continue;
            
            dp[i+1][t-1] = min(dp[i+1][t-1], dp[i][t] + ((t> T) ? 0 : a));
            dp[i+1][t]   = min(dp[i+1][t]  , dp[i][t] + ((t== T) ? 0 : b));
            dp[i+1][t+1] = min(dp[i+1][t+1], dp[i][t] + ((t< T) ? 0 : a));
        }
    }
    
    // 결과값
    int ret = INF; 
    for(int t=0;t<=50;t++){
        ret = min(ret,dp[n][t]);
    }
    return ret;
}