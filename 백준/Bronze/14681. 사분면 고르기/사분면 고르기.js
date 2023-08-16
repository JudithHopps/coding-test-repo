// 값 입력받는 코드
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
rl.on('line', function (line) {
  input.push(line);
}).on('close', function (){
  input = input.map((item) => +item);
  solution(input[0], input[1]);
  process.exit();
});

// 풀이코드
function solution(x, y) {
    let answer = 0

    if (x>0) {
        answer += y > 0 ? 1 : 4
    } else {
        answer += y > 0 ? 2 : 3
    }

    console.log(answer)
}