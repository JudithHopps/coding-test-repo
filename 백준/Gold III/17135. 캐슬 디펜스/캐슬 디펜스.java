import java.util.*;
import java.io.*;

public class Main {

    static final int INF = 987654321;
    static int n, m, d, all, ret;
    static int[][] a = new int[20][20];
    static int[][] b = new int[20][20];
    static int[][] visited = new int[20][20];
    static List<Pair> v = new ArrayList<>();
    static List<Pair> now = new ArrayList<>();

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return o.first - this.first;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
                if (a[i][j] == 1) {
                    v.add(new Pair(i, j));
                    all++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    for (int p = 0; p < n; p++)
                        b[p] = Arrays.copyOf(a[p], m);
                    now = new ArrayList<>(v);
                    go(new int[]{i, j, k}, 0);
                }
            }
        }
        System.out.println(ret);
    }

    static void check() {
        int cnt = 0;
        List<Pair> temp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 1) {
                    temp.add(new Pair(i, j));
                    cnt++;
                }
            }
        }
        now = temp;
    }

    static void move() {
        if (now.isEmpty())
            return;
        Collections.sort(now);
        for (Pair it : now) {
            b[it.first][it.second] = 0;
            if (it.first + 1 != n)
                b[it.first + 1][it.second] = 1;
        }
    }

    static void go(int[] solder, int cnt) {
        ret = Math.max(ret, cnt);
        if (now.isEmpty())
            return;
        for (int[] row : visited)
            Arrays.fill(row, 0);
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            int min = INF;
            int y = n, x = n;
            for (Pair it : now) {
                int dist = Math.abs(n - it.first) + Math.abs(solder[i] - it.second);
                if (dist > d)
                    continue;
                if (min > dist || (min == dist && x > it.second)) {
                    min = dist;
                    y = it.first;
                    x = it.second;
                }
            }
            if (visited[y][x] == 1 || min == INF)
                continue;
            visited[y][x] = 1;
            b[y][x] = 0;
            sum++;
        }
        check();
        move();
        check();
        go(solder, cnt + sum);
    }
}
