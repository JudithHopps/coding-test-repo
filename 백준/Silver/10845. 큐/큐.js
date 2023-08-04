var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');

let queue = []
let answer = []

for (let i = 1;i<input.length; i++) {
    if (input[i] == "front") {
        const temp = queue.length? queue[0] : -1
        answer.push(temp)
        continue;
    }
    else if (input[i] == "back") {
        const temp =queue.length ? queue[queue.length-1] : -1
        answer.push(temp)
        continue;
    }
    else if (input[i] == "size") {
        const temp = queue.length
        answer.push(temp)
        continue;
    }
    else if (input[i] == "empty") {
        const temp = queue.length? 0 : 1
        answer.push(temp)
        continue;
    }
    else if (input[i] == "pop") {
        const temp = queue.length? queue.shift() : -1 
        answer.push(temp)
        continue;
    }
    else {
        const cur = input[i].split(' ')
        const temp = cur[1]
        queue.push(temp)
    }
}

console.log(answer.map(v=>Number(v)).join('\n'))
