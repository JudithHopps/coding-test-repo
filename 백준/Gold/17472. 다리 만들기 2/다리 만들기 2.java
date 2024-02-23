import java.util.*;

public class Main {
    static final int MAX_N = 101;
    static final int MAX_M = 101;
    static final int MAX_LANDS = 1001;

    static int n, m;
    static int[][] board = new int[MAX_N][MAX_M];
    static int[][] weights = new int[MAX_LANDS][MAX_LANDS];

    static int[][] mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static void dfs(int x, int y, int flag) {
        board[x][y] = flag;
        for (int[] dir : mv) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0) continue;
            dfs(nx, ny, flag);
        }
    }

    static void findDist(int xLim, int yLim, boolean isRow) {
        for (int i = 0; i < xLim; i++) {
            int cur = 0;
            int from = -1;
            for (int j = 0; j < yLim; j++) {
                int land = (isRow) ? board[i][j] : board[j][i];
                if (land > 0) {
                    if (from == -1) {
                        from = land;
                        cur = 0;
                    } else if (from != land) {
                        int minWeight = (weights[from][land] == 0) ? cur : Math.min(cur, weights[from][land]);
                        if (minWeight > 1) {
                            weights[from][land] = minWeight;
                            weights[land][from] = minWeight;
                        }
                        from = land;
                        cur = 0;
                    } else {
                        from = land;
                        cur = 0;
                    }
                } else if (from != -1) {
                    ++cur;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = scanner.nextInt();
                --board[i][j];
            }
        }

        // 섬 구분
        int landsSize = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    dfs(i, j, landsSize++);
                }
            }
        }

        // 최단 거리 찾기
        findDist(n, m, true);
        findDist(m, n, false);

        // MST 산출
        int[] minEdge = new int[MAX_LANDS];
        boolean[] visited = new boolean[MAX_LANDS];
        Arrays.fill(minEdge, Integer.MAX_VALUE);
        Arrays.fill(visited, false);
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));

        minEdge[1] = 0;
        pq.offer(new Pair<>(0, 1));

        int answer = 0;
        int c = 0;

        while (!pq.isEmpty()) {
            Pair<Integer, Integer> minVertex = pq.poll();
            int weight = minVertex.getKey();
            int no = minVertex.getValue();
            if (visited[no]) continue;

            answer += weight;
            visited[no] = true;

            if (++c == landsSize - 1) break;

            for (int i = 1; i < landsSize; i++) {
                if (!visited[i] && weights[no][i] != 0 && weights[no][i] < minEdge[i]) {
                    minEdge[i] = weights[no][i];
                    pq.offer(new Pair<>(minEdge[i], i));
                }
            }
        }

        System.out.println((c == landsSize - 1) ? answer : -1);
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}
