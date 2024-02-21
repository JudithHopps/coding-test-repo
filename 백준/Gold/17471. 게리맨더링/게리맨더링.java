import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int n, ret = 987654321;
    static int[] a = new int[14];
    static ArrayList<Integer>[] adj = new ArrayList[14]; // ArrayList 배열로 변경
    static int[] parent = new int[14];
    static boolean[] visited = new boolean[14];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>(); // ArrayList 초기화
        }
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>(); // ArrayList 초기화
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            for (int j = 0; j < m; j++) {
                int temp = Integer.parseInt(st.nextToken());
                adj[i].add(temp);
                adj[temp].add(i); // 양방향 그래프이므로 반대 방향도 추가
            }
        }

        for (int i = 1; i < (1 << n) - 1; i++) {
            for (int j = 1; j <= n; j++) {
                parent[j] = 0;
            }
            for (int j = 1; j <= n; j++) {
                visited[j] = false;
            }
            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    parent[j + 1] = 1;
                    idx1 = j + 1;
                } else {
                    idx2 = j + 1;
                }
            }

            MyPair team1 = go(idx1, 1);
            MyPair team2 = go(idx2, 0);

            if (team1.first + team2.first == n) {
                ret = Math.min(ret, Math.abs(team1.second - team2.second));
            }
        }

        bw.write((ret == 987654321 ? -1 : ret) + "\n");

        br.close();
        bw.close();
    }

    static class MyPair {
        int first, second;

        MyPair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static MyPair go(int here, int value) {
        int[] ret = {1, a[here]};
        visited[here] = true;
        for (int there : adj[here]) {
            if (!visited[there] && parent[there] == value) {
                MyPair temp = go(there, value);
                ret[0] += temp.first;
                ret[1] += temp.second;
            }
        }
        return new MyPair(ret[0], ret[1]);
    }
}
