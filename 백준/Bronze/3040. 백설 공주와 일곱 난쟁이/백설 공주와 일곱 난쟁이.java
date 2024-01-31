import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static final int n = 9;
    static int[] a = new int[10];
    static ArrayList<Integer> ret = new ArrayList<>();

    static boolean go(int idx, ArrayList<Integer> v, int sum) {
        if (v.size() == 7) {
            if (sum == 100) {
                ret = new ArrayList<>(v);
                return true;
            }
            return false;
        }

        for (int i = idx + 1; i < n; i++) {
            v.add(a[i]);
            if (go(i, v, sum + a[i])) {
                return true;
            }
            v.remove(v.size() - 1);
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        if (go(-1, new ArrayList<>(), 0)) {
            for (int vv : ret) {
                System.out.println(vv);
            }
        } else {
            System.out.println("No combination found.");
        }
    }
}
