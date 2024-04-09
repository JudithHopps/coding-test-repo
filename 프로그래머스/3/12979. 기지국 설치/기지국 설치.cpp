#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> ST; 
int N,W;
int go(int idx){
    if(idx >= N+1) return 0;
    
    bool flag = false;
    
    for(int st : ST){
        if (idx>= st-W && idx <= st + W ){
            idx = st;
            flag = true;
            break;
        }
    }
    
    if(flag) return go(idx+W+1);
    
    else return go(idx+2*W+1) + 1; 
    
}

int solution(int n, vector<int> stations, int w)
{
    N = n;
    ST =  stations;
    W = w;
    
    return go(1);
}