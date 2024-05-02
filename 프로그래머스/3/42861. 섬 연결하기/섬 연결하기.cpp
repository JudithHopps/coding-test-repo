#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 10000;
int parent[104]; 

void init(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

int find(int node){
    if(parent[node] == node ) return node;
    return parent[node] = find(parent[node]);
}

int uni(int a, int b,int d){
    if(find(a) == find(b)) return 0;
    parent[find(b)] = find(a);
    return d; 
}
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int ret = 0;
    
    init(n);
    sort(costs.begin(),costs.end(),cmp);
    
    for(vector<int> it : costs){
        int s = it[0];
        int e = it[1];
        int d = it[2];
        
        if(s!= e){
             ret += uni(s,e,d);
        }
       
    }
    
    return ret;
}