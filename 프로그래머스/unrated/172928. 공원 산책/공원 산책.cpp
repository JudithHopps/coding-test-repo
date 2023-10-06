#include <string>
#include <vector>
const int dy []={0,1,0,-1};
const int dx[]={1,0,-1,0};

using namespace std;

int ch(char b){
    if(b=='N') return 3;
    if(b=='S') return 1;
    if(b=='W') return 2;
    return 0;
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int n = park.size();
    int m = park[0].size();
    int y = 0, x= 0;
    bool flag =0;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park.size();j++){
            if(park[i][j]=='S') {
                y = i;
                x = j;
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    // printf("%d  ,  %d\n ",y,x);
    
    for(string s : routes){
        int dir = ch(s[0]);
        int cnt = s[2]-'0';
        
        int ny = y , nx = x;
        bool go = 1;
        // printf("dir  : %d\n",dir);
        while(cnt--){
            ny += dy[dir];
            nx += dx[dir];
           
            
            if(ny <0||nx<0||ny>=n|| nx>=m|| park[ny][nx] =='X' ){
                 // printf("stop   :  %d  ,  %d \n",ny,nx);
                go = 0; break;
            }
        }
        if(go) {
            y= ny , x= nx;
        }
        
        // printf("%d  ,  %d \n",y,x);
    }
    answer.push_back(y);answer.push_back(x);
    return answer;
}