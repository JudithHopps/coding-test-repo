const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number)
const answer = []

for (let i = 1 ; i<= input[1] ;i *=10){
    answer.push(input[0]* ( Math.floor( (input[1] % (i*10 ) )/i ) ))
}

answer.push(input[0] * input[1])

console.log(answer.join('\n'))