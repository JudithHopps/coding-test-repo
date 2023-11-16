function changeStart(weak, start, n) {
  if (start === 0) return weak;

  let v = [];
  for (let i = start; i < weak.length; i++) {
    v.push(weak[i]);
  }
  for (let i = 0; i < start; i++) {
    v.push(weak[i] + n);
  }
  return v;
}

function solution(n, weak, dist) {
  const INF = 987654321;
  let ret = INF;

  dist.sort();

  do {
    for (let i = 0; i < weak.length; i++) {
      let newWeak = changeStart(weak, i, n);
      let idx = 0,
        flag = 0;
      let cur = newWeak[0] + dist[0];

      for (let j = 0; j < weak.length; j++) {
        if (cur < newWeak[j]) {
          if (idx + 1 === dist.length) {
            flag = 1;
            break;
          }
          cur = newWeak[j] + dist[++idx];
        }
      }
      if (!flag) ret = Math.min(ret, idx + 1);
    }
  } while (next_permutation(dist));

  return ret === INF ? -1 : ret;
}

// Helper function for generating permutations
function next_permutation(arr) {
  let i = arr.length - 1;
  while (i > 0 && arr[i - 1] >= arr[i]) i--;
  if (i <= 0) return false;

  let j = arr.length - 1;
  while (arr[j] <= arr[i - 1]) j--;
  let temp = arr[i - 1];
  arr[i - 1] = arr[j];
  arr[j] = temp;

  j = arr.length - 1;
  while (i < j) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }

  return true;
}
