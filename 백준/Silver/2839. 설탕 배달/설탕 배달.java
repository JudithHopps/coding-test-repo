import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int INF = 987654321;
    static int n;
    static int ret = INF;
    static int[] dp;

    static int go(int n) {
        if (n < 0)
            return INF;
        int ret = dp[n];
        if (ret != INF)
            return ret;
        ret = Math.min(go(n - 3) + 1, go(n - 5) + 1);
        return dp[n] = ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        dp = new int[n + 4]; // 배열 크기를 입력값 n에 따라 동적으로 할당
        Arrays.fill(dp, INF);

        dp[3] = 1;
        dp[5] = 1;

        for (int i = 3; i <= n; i++) {
            if (dp[i] == INF)
                continue;
            if(i + 3 <= n)
                dp[i + 3] = Math.min(dp[i + 3], dp[i] + 1);
            if(i + 5 <= n)
                dp[i + 5] = Math.min(dp[i + 5], dp[i] + 1);
        }

        System.out.println(dp[n] == INF ? -1 : dp[n]);
    }
}
