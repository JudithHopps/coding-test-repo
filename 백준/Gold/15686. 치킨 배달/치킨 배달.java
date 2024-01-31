import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m, ret = 987654321;
    static int[][] a = new int[54][54];
    static ArrayList<int[]> chickenList = new ArrayList<>();
    static ArrayList<int[]> home = new ArrayList<>();
    static ArrayList<int[]> chickens = new ArrayList<>();

    static void combi(int idx, int[] selected, int current) {
        if (current == m) {
            updateChickenList(selected);
            return;
        }

        for (int i = idx + 1; i < chickens.size(); i++) {
            selected[current] = i;
            combi(i, selected, current + 1);
        }
    }

    static void updateChickenList(int[] selected) {
        int[] chickenCombo = new int[m];
        for (int i = 0; i < selected.length; i++) {
            chickenCombo[i] = selected[i];
        }
        chickenList.add(chickenCombo);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
                if (a[i][j] == 1)
                    home.add(new int[]{i, j});
                if (a[i][j] == 2)
                    chickens.add(new int[]{i, j});
            }
        }

        int[] selected = new int[m];
        combi(-1, selected, 0);

        for (int[] cList : chickenList) {
            int sum = 0;
            for (int[] h : home) {
                int mn = Integer.MAX_VALUE;
                for (int ch : cList) {
                    int d = Math.abs(h[0] - chickens.get(ch)[0]) + Math.abs(h[1] - chickens.get(ch)[1]);
                    mn = Math.min(mn, d);
                }
                sum += mn;
            }
            ret = Math.min(ret, sum);
        }

        System.out.println(ret);
    }
}
