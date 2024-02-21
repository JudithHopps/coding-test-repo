import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int n, ret;
    static int[][] a;

    static void go(int dir, int y, int x) {
        if (y == n - 1 && x == n - 1) {
            ret++;
            return;
        }

        int[] b = new int[4];
        if (dir == 1) {
            b[1] = 1;
            b[3] = 3;
        } else if (dir == 2) {
            b[2] = 2;
            b[3] = 3;
        } else {
            b[1] = 1;
            b[2] = 2;
            b[3] = 3;
        }

        for (int i = 1; i < 4; i++) {
            int vv = b[i];
            if (vv == 0) continue;
            int ny = y, nx = x;
            if (i == 1) {
                nx = x + 1;
                if (nx >= n || a[ny][nx] != 0) continue; // 인덱스 범위 및 장애물 확인
            } else if (i == 2) {
                ny = y + 1;
                if (ny >= n || a[ny][nx] != 0) continue; // 인덱스 범위 및 장애물 확인
            } else if (i == 3) {
                ny = y + 1;
                nx = x + 1;
                if (ny >= n || nx >= n || a[ny][nx] != 0 || a[y][x + 1] != 0 || a[y + 1][x] != 0) continue; // 인덱스 범위 및 장애물 확인
            }

            go(vv, ny, nx);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        a = new int[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        go(1, 0, 1);
        bw.write(Integer.toString(ret));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}
