import java.util.Scanner;

public class Main {
    static int n, m;
    static int[] arr;

    public static void goMan(int b) {
        for (int i = 1; i * b <= n; i++) {
            arr[i * b] ^= 1;
        }
    }

    public static void goWo(int b) {
        arr[b] ^= 1;
        for (int i = 1; (b - i >= 1 && b + i <= n); i++) {
            if (arr[b - i] != arr[b + i]) return;
            arr[b - i] ^= 1;
            arr[b + i] ^= 1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        arr = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }

        m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a == 1) {
                goMan(b);
            } else {
                goWo(b);
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
            if (i % 20 == 0) System.out.println();
        }
    }
}
