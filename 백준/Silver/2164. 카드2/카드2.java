import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ret;
        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = 1; i <= n; i++) {
            dq.addLast(i);
        }

        while (true) {
            if (dq.size() == 1)
                break;
            dq.removeFirst();
            int now = dq.peekFirst();
            dq.removeFirst();
            dq.addLast(now);
        }

        System.out.println(dq.peekFirst());
        scanner.close();
    }
}
