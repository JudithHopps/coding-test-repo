#include <string>
#include <vector>

using namespace std;

void rot(vector<vector<int>> & key,int m){
    vector<vector<int>> temp(m, vector<int>(m, 0));

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            temp[i][j] = key[m-j-1][i];
        }
    }
    key = temp;
    return;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size() , cnt =0;
    int holl = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(lock[i][j] ==0) holl++;
        }
    }
    for(int k=0;k<4;k++){
        for(int i=-19;i<=19;i++){
            for(int j=-19;j<=19;j++){
                
                int cnt = 0, flag =0;
                for(int y = 0; y<m;y++){
                    for(int x = 0;x<m;x++){
                        int ny = y + i;
                        int nx = x + j;
                        if(ny<0||nx<0||ny>=n||nx>=n) continue;
                        if(lock[ny][nx] == 1 && key[y][x] == 1) flag = 1;
                        else if(lock[ny][nx] == 0 && key[y][x] == 1) cnt++;
                    }
                }
                if(cnt==holl && !flag ) return true;
            }
        }
        rot(key,m);
    }
    return false;
}