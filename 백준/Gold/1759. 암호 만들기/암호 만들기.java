import java.util.*;

public class Main {
    static int l, n, m;
    static char c;
    static Map<Integer, Integer> mp = new HashMap<>();
    static Map<Character, Integer> moum = new HashMap<>();
    static List<String> v = new ArrayList<>();

    static boolean check(String str) {
        boolean flag = false;
        int cnt = 0;

        for (char c : str.toCharArray()) {
            if (moum.containsKey(c))
                flag = true;
            else
                cnt++;
        }

        return flag && cnt >= 2;
    }

    static void go(int idx, StringBuffer str, int visited) {
        if (str.length() == n) {
            if (check(str.toString()))
                v.add(str.toString());
            return;
        }

        for (int i = str.charAt(str.length() - 1) + 1; i <= 'z'; i++) {
            if ((visited & (1 << (i - 'a'))) != 0)
                continue;
            if (!mp.containsKey(i))
                continue;
            str.append((char) i);
            go(idx + 1, str, visited | (1 << (i - 'a')));
            str.deleteCharAt(str.length() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();

        for (char c : "aeiou".toCharArray()) {
            moum.put(c, 1);
        }

        for (int i = 0; i < m; i++) {
            c = scanner.next().charAt(0);
            mp.put((int) c, 1);
        }
        StringBuffer s = new StringBuffer();
        for (int i = 'a'; i <= 'z'; i++) {
            if (!mp.containsKey(i))
                continue;
            s.append((char) i);
            go(0, s, 1 << (i - 'a'));
            s.deleteCharAt(s.length() - 1);
        }

        Collections.sort(v);

        for (String s1 : v) {
            System.out.println(s1);
        }
    }
}
