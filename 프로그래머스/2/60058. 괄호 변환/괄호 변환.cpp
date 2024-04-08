#include <string>
#include <vector>

using namespace std;

bool ch(string s){
    int l=0;
    for(char c : s){
         if(c=='(') l++;
         else if(l) l--;
         else return false;
    }
    return (l > 0 ? false : true);
}
string convert(string s){
    string next = "(";
    for(int i=1;i<s.size()-1;i++){
         if(s[i]=='(') next += ")";
         else next += "(";
    }
    next += ")";
    return next;
}
string go(string s){
    if(ch(s)) return s;
    
    int l=0,r=0, idx =0;
    
     for(;idx<s.size();idx++){
         char c= s[idx];
        if(c=='(') l++;
        else r++;
         
        if(l==r) break;
    }
    
    string a = s.substr(0,idx+1);
    string b = s.substr(idx+1);
    
    if(ch(a)){
        return a + go(b);
    } else {
        string ret = "(";
        ret += go(b);
        ret += ")";
        for(int i=1;i<a.size()-1;i++){
             if(a[i]=='(') ret += ")";
             else ret += "(";
        }
        return ret;
    }
}
string solution(string p) {
   return go(p);
   
}