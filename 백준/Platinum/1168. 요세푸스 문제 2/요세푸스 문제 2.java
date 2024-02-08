import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int[] tree = new int[200005];

    static void update(int idx, int val) {
        while (idx <= 200004) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    static int sum(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    static int getNumber(int index) {
        int left = 1, right = N;
        while (left <= right) {
            int mid = (left + right) / 2;
            int count = sum(mid);
            if (count >= index)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++)
            update(i, 1);

        int index = K;

        StringBuilder sb = new StringBuilder();
        sb.append("<");
        for (int i = 1; i <= N - 1; i++) {
            int number = getNumber(index);

            sb.append(number).append(", ");

            update(number, -1);

            index = index - 1 + K;
            index = (index - 1) % (N - i) + 1;
        }

        sb.append(getNumber(1)).append(">");

        System.out.println(sb.toString());
    }
}
