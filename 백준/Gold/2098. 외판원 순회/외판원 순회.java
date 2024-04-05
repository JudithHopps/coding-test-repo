
import java.util.*;

public class Main {
    static final int INF = 987654321;
    static int n;
    static int[][] a;
    static int[][] dp;

    static int go(int here, int visited) {
        if (visited == (1 << n) - 1) {
            return (a[here][0] != 0) ? a[here][0] : INF;
        }
        if (dp[here][visited] != -1)
            return dp[here][visited];
        int ret = INF;
        for (int next = 0; next < n; next++) {
            if (a[here][next] == 0)
                continue;
            if ((visited & (1 << next)) != 0)
                continue;
            ret = Math.min(ret, go(next, visited | (1 << next)) + a[here][next]);
        }
        return dp[here][visited] = ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        dp = new int[n][(1 << n)];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        System.out.println(go(0, 1));
        sc.close();
    }
}
