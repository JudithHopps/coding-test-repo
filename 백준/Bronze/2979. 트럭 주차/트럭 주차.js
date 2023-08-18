const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')

const [a,b,c] = input[0].split(' ').map(Number)

let answer = new Array(100).fill(0)

for (let i = 1 ;i < input.length; i++) {
    const [s,e] = input[i].split(' ').map(Number)
    for (let j = s;j<e;j++){
        answer[j]++;
    }
}
let sum = 0;
answer.filter(a=>a!==0).forEach((v)=>{
    sum += v===1? v*a : ( v===2? v*b : v*c) 
})

console.log(sum)