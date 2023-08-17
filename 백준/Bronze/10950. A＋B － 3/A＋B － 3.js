const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
const count = Number(input[0])
const answer = []
for (let i=0;i<count ; i++){
    const [a,b]=input[i+1].split(' ').map(Number)
    answer.push(a+b)
}

console.log(answer.join('\n'))