import java.util.Scanner;

public class Main {
    static int r, c, ret;
    static char[][] a;
    static boolean[] visited;
    static final int[] dy = {0, 0, 1, -1};
    static final int[] dx = {1, -1, 0, 0};

    static void go(int y, int x, int sum) {
        ret = Math.max(ret, sum);

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            int next = a[ny][nx] - 'A';
            if (visited[next])
                continue;
            visited[next] = true;
            go(ny, nx, sum + 1);
            visited[next] = false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        r = scanner.nextInt();
        c = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        a = new char[r][c];
        visited = new boolean[26]; // Assuming input characters are capital letters from A to Z

        for (int i = 0; i < r; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < c; j++) {
                a[i][j] = line.charAt(j);
            }
        }

        visited[a[0][0] - 'A'] = true;
        go(0, 0, 1);
        System.out.println(ret);
    }
}
