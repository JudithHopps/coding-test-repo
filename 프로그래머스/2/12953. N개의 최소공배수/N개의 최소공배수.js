
function lcm(n,m){
    return (n%m ? lcm(m, n%m) : m);
}
function cal(n, m){
    return n * m / lcm(n,m);
}
function solution(arr) {
    let ret = arr[0];
    for(let i=1;i<arr.length;i++){
        ret = cal(ret,arr[i]);
    }
    
    return ret;
}