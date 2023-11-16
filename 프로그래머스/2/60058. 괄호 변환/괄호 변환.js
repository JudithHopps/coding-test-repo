function ch(p){
    if(p.length ==0) return true;
    
    let cnt = 0;
    for(let c of p){
        if(c=='(') cnt++;
        else cnt--;
        if(cnt<0) return 0;
    }
    return cnt ==0;
}
function go(p){
    if(p.length==0 || ch(p)) return p;
    
    let i=0,l=0,r=0;
    for(;i<p.length;i++){
        if(p[i]=='(')l++;
        else r++;
        if(l==r) break;
    }
    
    const a = p.substr(0,i+1);
    const b = p.substr(i+1);
    
    if(ch(a)){
        return a + go(b);
    }
    else {
        let str = "("
        str += go(b);
        str += ")";
        
        for(let i=1;i<a.length-1;i++){
            if(a[i]=='(') str += ')';
            else str += '(';
        }
        return str;
    }
}
function solution(p) {
    var answer = go(p);
    return answer;
}