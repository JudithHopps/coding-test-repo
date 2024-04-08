#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

vector<int> changeStartIdx(vector<int> weak, int start,int n){
    if(start ==0) return weak;
    
    vector<int> temp;
    for(int i=start;i<weak.size();i++) temp.push_back(weak[i]);
    for(int i=0;i<start;i++) temp.push_back(weak[i] + n);
    
    return temp;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int ret = INF;
    sort(dist.begin(),dist.end());
    
    do{
        for(int j=0;j<weak.size();j++){
            vector<int> Weak = changeStartIdx(weak,j,n);
            int idx = 0, flag = 0;
            int curr = Weak[0] + dist[idx];
            for(int i=1;i<Weak.size();i++){
                if(Weak[i] > curr){
                    if(idx +1 == dist.size()){
                        flag = 1; break;
                    }
                    curr = Weak[i] + dist[++idx];
                }
            }
            if(!flag) ret = min(ret,idx+1);
        }
        
        
    } while(next_permutation(dist.begin(),dist.end()));
    return (ret==INF ? -1 : ret);
}