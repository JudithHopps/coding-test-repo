import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int k = scanner.nextInt();
        int c = scanner.nextInt();
        int ret = 1;
        int now = 1;
        int[] cnt = new int[3004];
        int[] a = new int[6000004];

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            a[n + i] = a[i];
        }

        cnt[c]++;

        for (int i = 0; i < k - 1; i++) {
            cnt[a[i]]++;
            if (cnt[a[i]] == 1)
                now++;
        }

        for (int start = 0; start < n; start++) {
            cnt[a[start + k - 1]]++;
            if (a[start + k - 1] != c && cnt[a[start + k - 1]] == 1) {
                now++;
            }
            ret = Math.max(ret, now);
            cnt[a[start]]--;
            if (cnt[a[start]] == 0)
                now--;
        }
        System.out.println(ret);
    }
}
