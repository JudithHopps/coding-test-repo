#include <string>
#include <vector>

using namespace std;

vector<string> convert(string s,int siz){
    vector<string> v;
    for(int i=0;i<s.size();i+=siz){
        v.push_back(s.substr(i,siz));
    }
    
    return v;
}
int solution(string s) {
    int n = s.size();
    int ret = s.size();
    
    for(int siz=n/2; siz>=1;siz--){
        vector<string> v = convert(s,siz);
        string pre = v[0], str = "";
        int cnt = 1;
        
        for(int i=1;i<v.size();i++){
            string now =v[i] ;
            if(pre==now) cnt++;
            else {
                if(cnt != 1) str+= to_string(cnt);
                str += pre;
                pre = now;
                cnt = 1;
            }
        }
        
        if(cnt != 1) str+= to_string(cnt);
        str += pre;
        ret = (ret>str.size() ? str.size(): ret);
        
    }
    return ret;
}