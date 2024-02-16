import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static String str;
    static boolean flag = false;
    static int r, c, ret;
    static int[][] visited;
    static char[][] a;
    static final int[] dy = {-1, 0, 1};
    static final int[] dx = {1, 1, 1};

    static void dfs(int y, int x) {
        if (x == c - 1) {
            flag = true;
            ret++;
            return;
        }

        for (int dir = 0; dir < 3; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == 'x') continue;
            if (visited[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            dfs(ny, nx);
            if (flag) return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] rc = br.readLine().split(" ");
        r = Integer.parseInt(rc[0]);
        c = Integer.parseInt(rc[1]);

        a = new char[r][c];
        visited = new int[r][c];

        for (int i = 0; i < r; i++) {
            str = br.readLine();
            for (int j = 0; j < c; j++) {
                a[i][j] = str.charAt(j);
            }
        }

        for (int i = 0; i < r; i++) {
            dfs(i, 0);
            flag = false;
        }

        System.out.println(ret);
    }
}
