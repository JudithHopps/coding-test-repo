#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = lock.size();
    int m = key.size();
    vector<pair<int,int>> needs;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lock[i][j]==0){
                    needs.push_back({i,j});
                }
            }
   }
    
    // 4번 회전 X 20 * 20 
    for(int k=0; k<4; k++){
        vector<pair<int,int>> have;
        vector<vector<int>> temp = key; 
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = key[j][m-i-1];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==1) {
                    have.push_back({i,j});
                }
            }
        }
        
        key = temp;
        
        for(int i=-n;i<=n;i++){
            for(int j=-n;j<=n;j++){
                int sy = i, sx = j,cnt = 0;
                bool flag = true;
                for(auto it : have){
                    int ny = it.first + sy;
                    int nx = it.second + sx;
                    if(ny<0||nx<0||ny>=n||nx>=n) continue;
                    if(lock[ny][nx]){
                        flag = false; break;
                    }
                    cnt++;
                }
                if(flag && cnt == needs.size()) return true;
            }
        }
    }
    
    return answer;
}