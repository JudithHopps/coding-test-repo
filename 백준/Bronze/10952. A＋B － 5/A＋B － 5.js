const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')

const answer = []

for (let i=0;i<input.length-1;i++){
    const [a,b] = input[i].split(' ').map(Number)
    answer.push(a+b)
}

console.log(answer.join('\n'))
      