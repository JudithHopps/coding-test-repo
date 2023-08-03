function solution(citations) {
    citations.sort((a,b)=>a-b)
    for(let i=Math.max(...citations);i>=0;i--){
        const more = citations.filter(v=>v>=i).length
        const less = citations.filter(v=>v<=i).length
        if(more>=i) return i
    }
}