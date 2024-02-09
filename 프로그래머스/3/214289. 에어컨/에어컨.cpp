#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int dp[1004][54];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
  
    int n = onboard.size();
    t1+=10, t2+=10,temperature+=10;
    
    fill(&dp[0][0], &dp[0][0] +1004 *54,INF);
    
    dp[0][temperature] = 0;
    
    for(int i=0;i<n;i++){
        for(int t=0;t<=50;t++){
            if(onboard[i] &&(t < t1 || t2 < t)) continue;
            if(dp[i][t] == INF) continue; 
            dp[i+1][t+1] = min(dp[i+1][t+1], dp[i][t] + (temperature > t ? 0 : a));
            dp[i+1][t]   = min(dp[i+1][t], dp[i][t] + (temperature == t? 0 : b));
            dp[i+1][t-1] = min(dp[i+1][t-1] , dp[i][t] + (temperature < t ? 0 : a));
        }
    }
    int ret = INF;
    for(int t=0;t<=50;t++){
        ret = min(ret, dp[n][t]);
    }
    
    
    return ret;
}
