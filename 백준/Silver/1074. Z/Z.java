import java.util.Scanner;

public class Main {
    static int n, r, c, cnt = -1, ret, siz;

    public static void go(int siz, int y, int x) {
        if (siz == 1) {
            cnt++;
            if (y == r && x == c) {
                ret = cnt;
            }
            return;
        }
        int next = siz / 2;

        int xr = (x + next <= c && c < x + siz) ? 1 : 0;
        int yr = (y + next <= r && r < y + siz) ? 1 : 0;
        int mul = yr << 1 | xr;

        cnt += mul * next * next;
        go(next, y + yr * next, x + xr * next);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();

        siz = 1 << n;

        go(siz, 0, 0);

        System.out.println(ret);
        sc.close();
    }
}
