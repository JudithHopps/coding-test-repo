import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[500004];
        int[] ret = new int[500004];
        Stack<Pair> st = new Stack<>();

        StringTokenizer stz = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(stz.nextToken());

            while (!st.isEmpty() && st.peek().second < a[i]) {
                st.pop();
            }
            if (!st.isEmpty() && st.peek().second > a[i]) {
                ret[i] = st.peek().first;
            }
            st.push(new Pair(i, a[i]));
        }

        for (int i = 1; i <= n; i++) {
            bw.write(ret[i] + " ");
        }

        // BufferedWriter를 사용한 후에는 반드시 flush()와 close()를 호출해줘야 합니다.
        bw.flush();
        bw.close();
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
