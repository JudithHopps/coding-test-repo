import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static int n;
    static long ret = 3000000000L;
    static ArrayList<long[]> taste = new ArrayList<>();

    public static void goBit() {
        for (int i = 1; i < (1 << n); i++) {
            long sum1 = 0, sum2 = 0;

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    if (sum1 == 0) {
                        sum1 = taste.get(j)[0];
                    } else {
                        sum1 *= taste.get(j)[0];
                    }
                    sum2 += taste.get(j)[1];
                }
            }
            ret = Math.min(ret, Math.abs(sum1 - sum2));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            taste.add(new long[]{a, b});
        }

        goBit();

        System.out.println(ret);
    }
}
