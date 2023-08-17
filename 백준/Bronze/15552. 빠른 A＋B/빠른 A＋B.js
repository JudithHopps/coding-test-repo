const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
const answer = []
for (let i = 1;i<input.length;i++){
    const [a,b] = input[i].split(' ').map(Number)
    answer.push(a+b)
}

console.log(answer.join('\n'))