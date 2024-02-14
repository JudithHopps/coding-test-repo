import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;

    public static String go(int y, int x, int siz) {
        String ret = "";
        boolean flag = false;

        int now = a[y][x];
        for (int i = y; i < y + siz; i++) {
            for (int j = x; j < x + siz; j++) {
                if (now != a[i][j]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (!flag)
            return Integer.toString(now);
        else {
            ret += "(";
            ret += go(y, x, siz / 2);
            ret += go(y, x + siz / 2, siz / 2);
            ret += go(y + siz / 2, x, siz / 2);
            ret += go(y + siz / 2, x + siz / 2, siz / 2);
            ret += ")";
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        a = new int[n][n];

        for (int i = 0; i < n; i++) {
            String str = sc.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = str.charAt(j) - '0';
            }
        }

        System.out.println(go(0, 0, n));
        sc.close();
    }
}
