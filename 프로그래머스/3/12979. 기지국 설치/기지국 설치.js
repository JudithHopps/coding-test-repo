function solution(n, stations, w) {
    let pre = 0, ret =0;
    const len = w*2 +1;
    for(let i=0;i<stations.length;i++){
        let a = stations[i] - w - 1 - pre;
        let b = Math.ceil(a/len);
        ret += b;
        pre = stations[i] +w;
    }
    ret += Math.ceil( (n-pre) / len);
    return ret;
}