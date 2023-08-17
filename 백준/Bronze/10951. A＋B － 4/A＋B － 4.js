const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(v=>v.split(' ').map(Number))

const answer = []
for (const s of input) {
    const sum = s.reduce((a,b)=>a+b,0)
    console.log(sum)
    
}
console.log(answer.join('\r\n'))