import java.util.Scanner;

public class Main {
    static final int MOD = 1000000;
    static final int P = 15 * (MOD / 10);
    static int[] dp = new int[P + 4];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        if (n <= 1) {
            System.out.println(n);
        } else {
            init();
            System.out.println(dp[(int)(n % P)]);
        }
    }

    static int f(int n) {
        if (n <= 1) return n;
        if (dp[n] != 0) return dp[n];
        return (f(n - 1) + f(n - 2)) % MOD;
    }

    static void init() {
        for (int i = 0; i <= P; i++) {
            dp[i] = f(i);
        }
    }
}
