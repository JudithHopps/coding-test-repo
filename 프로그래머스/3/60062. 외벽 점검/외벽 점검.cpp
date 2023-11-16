#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

vector<int> changeStart(vector<int> weak,int start,int n){
    if(start ==0) return weak;
    vector<int> v;
    for(int i = start;i<weak.size();i++) v.push_back(weak[i]);
    for(int i=0;i<start;i++) v.push_back(weak[i] + n);
    return v;
}
int solution(int n, vector<int> weak, vector<int> dist)
{
  int ret = INF;

  sort(dist.begin(), dist.end());

  do{
      for(int j=0;j<weak.size();j++){
          vector<int> newWeak = changeStart(weak,j,n);
          int idx = 0, flag = 0;
          int cur = newWeak[0] + dist[0];
          
          for(int i = 0;i<weak.size();i++){
              if(cur < newWeak[i]){
                  if(idx+1 == dist.size()) {
                      flag = 1; break;
                  }
                  cur = newWeak[i] + dist[++idx];
              }
          }
          if(!flag ) ret = min(ret,idx+1);
      } 
  }while(next_permutation(dist.begin(),dist.end()));

  return (ret == INF ? -1 : ret);
}