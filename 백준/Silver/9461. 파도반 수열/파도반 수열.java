import java.util.Scanner;

public class Main {
    static int t, n;
    static long[] dp = new long[104];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        init();

        t = scanner.nextInt();
        while (t-- > 0) {
            n = scanner.nextInt();
            System.out.println(dp[n]);
        }
    }

    static void init() {
        dp[0] = 0;
        dp[1] = dp[2] = dp[3] = 1;
        dp[4] = dp[5] = 2;
        for (int i = 6; i < 101; i++) {
            dp[i] = dp[i - 1] + dp[i - 5];
        }
    }
}
