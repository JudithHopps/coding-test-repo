import java.util.*;

public class Main {
    static int n, m;
    static int[][] a = new int[104][104];
    static int[][] visited = new int[104][104];
    static int cnt, cheese;
    static ArrayList<Pair<Integer, Integer>> v = new ArrayList<>();
    static final int[] dy = {0, 0, 1, -1};
    static final int[] dx = {1, -1, 0, 0};

    static boolean end() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    static void dfs(int y, int x) {
        visited[y][x] = 1;
        if (a[y][x] != 0) {
            v.add(new Pair<>(y, x));
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            dfs(ny, nx);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        while (true) {
            cheese = v.size();

            for (Pair<Integer, Integer> it : v) {
                a[it.first][it.second] = 0;
            }
            v.clear();

            if (end()) {
                break;
            }
            for (int i = 0; i < 104; i++) {
                Arrays.fill(visited[i], 0);
            }
            dfs(0, 0);
            cnt++;
        }

        System.out.println(cnt);
        System.out.println(cheese);
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
