import java.io.*;

public class Main {
    static final int n = 10;
    static final int INF = 987654321;
    static int[][] a = new int[14][14];
    static int ret = INF;
    static int[][] visited = new int[14][14];
    static int sy, sx;
    static int[] cnt = new int[10];
    static boolean flag = false;

    static boolean ch(int y, int x, int siz) {
        if (y + siz > n || x + siz > n) return false;

        for (int ny = y; ny < y + siz; ny++) {
            for (int nx = x; nx < x + siz; nx++) {
                if (a[ny][nx] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    static void paint(int y, int x, int siz, int val) {
        for (int ny = y; ny < y + siz; ny++) {
            for (int nx = x; nx < x + siz; nx++) {
                a[ny][nx] = val;
            }
        }
    }

    static void go(int y, int x, int use) {
        if (ret <= use) return;
        if (y >= n) {
            ret = Math.min(ret, use);
            return;
        }
        if (x >= n) {
            go(y + 1, 0, use);
            return;
        }
        if (a[y][x] == 0) {
            go(y, x + 1, use);
            return;
        }

        for (int siz = 5; siz >= 1; siz--) {
            if (cnt[siz] == 5) continue;
            if (!ch(y, x, siz)) continue;
            cnt[siz]++;
            paint(y, x, siz, 0); // 색종이 덮기
            go(y, x + 1, use + 1);
            paint(y, x, siz, 1); // 색종이 제거
            cnt[siz]--;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(input[j]);
                if (a[i][j] == 1 && !flag) {
                    flag = true;
                    sy = i;
                    sx = j;
                }
            }
        }

        go(0, 0, 0);

        // 출력
        bw.write((ret == INF ? -1 : ret) + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}
