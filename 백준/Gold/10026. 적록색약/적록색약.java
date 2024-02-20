import java.util.*;

public class Main {
    static String str;
    static int n;
    static int[][] a = new int[104][104];
    static int[][] visited = new int[104][104];
    static int[][] V = new int[104][104];
    static int ret1, ret2;
    static ArrayList<Pair<Integer, Integer>> v = new ArrayList<>();
    static final int[] dy = {0, 0, -1, 1};
    static final int[] dx = {1, -1, 0, 0};

    static void dfs(int val, int y, int x) {
        visited[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (a[ny][nx] != val || visited[ny][nx] == 1)
                continue;
            dfs(val, ny, nx);
        }
    }

    static void dfs2(boolean flag, int y, int x) {
        V[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if ((a[ny][nx] == 3) != flag)
                continue;
            if (V[ny][nx] == 1)
                continue;
            dfs2(flag, ny, nx);
        }
    }

    static void go() {
        for (int i = 0; i < 104; i++) {
            Arrays.fill(visited[i], 0);
            Arrays.fill(V[i], 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    dfs(a[i][j], i, j);
                    ret1++;
                }

                if (V[i][j] == 0) {
                    dfs2(a[i][j] == 3, i, j);
                    ret2++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            str = scanner.next();
            for (int j = 0; j < n; j++) {
                if (str.charAt(j) == 'R')
                    a[i][j] = 1;
                if (str.charAt(j) == 'G') {
                    a[i][j] = 2;
                    v.add(new Pair<>(i, j));
                }
                if (str.charAt(j) == 'B')
                    a[i][j] = 3;
            }
        }

        go();

        System.out.println(ret1 + " " + ret2);
    }
}

class Pair<A, B> {
    A first;
    B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }
}
