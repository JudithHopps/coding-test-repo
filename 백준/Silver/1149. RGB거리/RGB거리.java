import java.util.Scanner;
 
public class Main {
	static final int INF = 987654321;
    static final int m = 3;
    static int n, ret;
    static int[][] a, dp;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        a = new int[1004][m];
        dp = new int[1004][m];
        ret = INF;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        for (int i = 0; i < m; i++) {
            ret = Math.min(ret, go(0, i));
        }

        System.out.println(ret);
        scanner.close();
    }

    static int go(int idx, int now) {
        if (idx == n) {
            return 0;
        }

        if (dp[idx][now] != 0) return dp[idx][now];

        dp[idx][now] = INF;

        for (int i = 0; i < m; i++) {
            if (now == i) continue;
            dp[idx][now] = Math.min(dp[idx][now], go(idx + 1, i) + a[idx][i]);
        }

        return dp[idx][now];
    }
}