import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] dp = new int[100004];

        for (int i = 0; i < n; i++) {
            int w = scanner.nextInt();
            int p = scanner.nextInt();

            for (int j = k; j >= w; j--) {
                dp[j] = Math.max(dp[j], dp[j - w] + p);
            }
        }

        System.out.println(dp[k]);
    }
}
