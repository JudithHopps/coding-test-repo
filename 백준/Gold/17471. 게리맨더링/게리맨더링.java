import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 987654321;
    static int n, ret = INF;
    static int[] a, visited, parent;
    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        visited = new int[n];
        parent = new int[n];
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        String[] split = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(split[i]);
        }

        for (int i = 0; i < n; i++) {
            split = br.readLine().split(" ");
            int m = Integer.parseInt(split[0]);
            for (int j = 0; j < m; j++) {
                int b = Integer.parseInt(split[j + 1]) - 1;
                adj[i].add(b);
                adj[b].add(i);
            }
        }

        for (int i = 1; i < (1 << n) - 1; i++) {
            int idx1 = -1, idx2 = -1;
            init();
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    if (idx1 != -1)
                        union_group(idx1, j);
                    idx1 = j;
                } else {
                    if (idx2 != -1)
                        union_group(idx2, j);
                    idx2 = j;
                }
            }
            Arrays.fill(visited, 0);
            Pair A = go(idx1, find_root(idx1));
            Pair B = go(idx2, find_root(idx2));
            if (A.second + B.second == n) {
                ret = Math.min(ret, Math.abs(A.first - B.first));
            }
        }
        System.out.println(ret == INF ? -1 : ret);
    }

    static void init() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    static int find_root(int node) {
        if (node == parent[node])
            return node;
        parent[node] = find_root(parent[node]);
        return parent[node];
    }

    static void union_group(int A, int B) {
        int rootA = find_root(A);
        int rootB = find_root(B);
        if (rootA == rootB)
            return;
        parent[rootB] = rootA;
    }

    static Pair go(int idx, int val) {
        visited[idx] = 1;
        Pair temp = new Pair(a[idx], 1);

        for (int vv : adj[idx]) {
            if (visited[vv] != 0)
                continue;
            if (parent[vv] != val)
                continue;
            Pair now = go(vv, val);
            temp.first += now.first;
            temp.second += now.second;
        }

        return temp;
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
