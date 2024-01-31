import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] a = new int[54];
    static String s;

    static int cal(int visited) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == (a[i] & visited)) {
                cnt++;
            }
        }
        return cnt;
    }

    static int go(int idx, int cnt, int visited) {
        if (cnt > k) return 0;
        if (idx == 26) return cal(visited);

        int ret = go(idx + 1, cnt + 1, visited | (1 << idx));

        if (idx != 0 && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && 'c' - 'a' != idx) {
            ret = Math.max(ret, go(idx + 1, cnt, visited));
        }

        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        k = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            s = scanner.next();
            for (char c : s.toCharArray()) {
                a[i] |= (1 << (c - 'a'));
            }
        }

        System.out.println(go(0, 0, 0));
        scanner.close();
    }
}
