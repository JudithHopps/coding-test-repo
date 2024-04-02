import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static final int INF = 987654321;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 0;

        while (true) {
            t++;
            int n = scanner.nextInt();
            if (n == 0) break;

            int[][] a = new int[n][n];
            int[][] dist = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = scanner.nextInt();
                }
            }

            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], INF);
            }
            dist[0][0] = a[0][0];
            PriorityQueue<int[]> pq = new PriorityQueue<>((a1, a2) -> a1[0] - a2[0]);
            pq.add(new int[]{dist[0][0], 0});

            while (!pq.isEmpty()) {
                int[] cur = pq.poll();
                int y = cur[1] / 200;
                int x = cur[1] % 200;
                int d = cur[0];

                if (dist[y][x] != d) continue;

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if (dist[ny][nx] > d + a[ny][nx]) {
                        dist[ny][nx] = d + a[ny][nx];
                        pq.add(new int[]{dist[ny][nx], ny * 200 + nx});
                    }
                }
            }
            int ret = dist[n - 1][n - 1];
            System.out.println("Problem " + t + ": " + ret);
        }
    }

    static final int[] dy = {0, 0, 1, -1};
    static final int[] dx = {1, -1, 0, 0};
}
