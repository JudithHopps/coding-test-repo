#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
map<int,int> mp;
priority_queue<pair<int,int>> pq;
int solution(int k, vector<int> tangerine) {
    int ret = 0;
    
    for(int t : tangerine){
        mp[t]++;
    }
    
    for(auto it : mp){
        pq.push({it.second,it.first});
    }
    while(pq.size()){
        k -= pq.top().first;
        ret++;
        pq.pop();
        if(k<=0) break;
    }
    
    
    return ret;
}