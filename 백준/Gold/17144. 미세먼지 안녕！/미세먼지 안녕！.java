import java.util.*;

public class Main {
    static int R, C, T;
    static int[][] a, temp;
    static int ret, y, x;
    static List<Pair<Integer, Integer>> v1, v2;
    static int[] dy = {0, -1, 0, 1};
    static int[] dx = {1, 0, -1, 0};
    static int[] dy2 = {0, 1, 0, -1};
    static int[] dx2 = {1, 0, -1, 0};

    static void dfs(int y, int x, int d, int[] dy, int[] dx, List<Pair<Integer, Integer>> v) {
        if (a[y][x] == -1) return;

        v.add(new Pair<>(y, x));

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
            d = (d + 1) % 4;
            ny = y + dy[d];
            nx = x + dx[d];
        }

        dfs(ny, nx, d, dy, dx, v);
    }

    static void findRoute() {
        dfs(y - 1, x + 1, 0, dy, dx, v1);
        dfs(y, x + 1, 0, dy2, dx2, v2);
    }

    static void mise() {
        temp = new int[R][C];
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (a[y][x] <= 0) continue;
                int q = a[y][x] / 5;

                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                    if (a[ny][nx] == -1) continue;
                    temp[ny][nx] += q;
                    temp[y][x] -= q;
                }
            }
        }
    }

    static void reOrder() {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (a[y][x] == -1) continue;
                a[y][x] += temp[y][x];
            }
        }
    }

    static void cleanAir(List<Pair<Integer, Integer>> v) {
        List<Integer> temp = new ArrayList<>();

        for (int i = 0; i < v.size() - 1; i++) {
            temp.add(a[v.get(i).first][v.get(i).second]);
        }

        for (int i = 1; i < v.size(); i++) {
            a[v.get(i).first][v.get(i).second] = temp.get(i - 1);
        }
        a[v.get(0).first][v.get(0).second] = 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        R = scanner.nextInt();
        C = scanner.nextInt();
        T = scanner.nextInt();

        a = new int[R][C];
        v1 = new ArrayList<>();
        v2 = new ArrayList<>();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                a[i][j] = scanner.nextInt();
                if (a[i][j] == -1) {
                    y = i;
                    x = j;
                }
            }
        }

        findRoute();

        while (T-- > 0) {
            mise();
            reOrder();
            cleanAir(v1);
            cleanAir(v2);
        }

        ret = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (a[i][j] > 0) {
                    ret += a[i][j];
                }
            }
        }

        System.out.println(ret);
    }

    static class Pair<A, B> {
        public final A first;
        public final B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
