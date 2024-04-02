import java.util.Scanner;

class Main {
    static class Shark {
        int y, x, s, dir, z, die;

        Shark() {
            y = x = s = dir = z = die = 0;
        }
    }

    static Shark[] s = new Shark[10004];
    static int[][] a = new int[100][100];
    static int[][] temp = new int[100][100];
    static int R, C, M, ret, cur;
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    static void getShark() {
        for (int i = 0; i < R; i++) {
            if (a[i][cur] != 0) {
                ret += s[a[i][cur]].z;
                s[a[i][cur]].die = 1;
                a[i][cur] = 0;
                return;
            }
        }
    }

    static void moveShark() {
        temp = new int[100][100];
        for (int i = 1; i <= M; i++) {
            if (s[i].die == 1) continue;

            int y = s[i].y;
            int x = s[i].x;
            int ss = s[i].s;
            int d = s[i].dir;

            int ny, nx;

            while (true) {
                ny = y + dy[d] * ss;
                nx = x + dx[d] * ss;
                if (ny >= 0 && nx >= 0 && nx < C && ny < R) break;

                if (d <= 1) {
                    if (ny < 0) {
                        ss -= y;
                        y = 0;
                    } else {
                        ss -= R - 1 - y;
                        y = R - 1;
                    }
                } else {
                    if (nx < 0) {
                        ss -= x;
                        x = 0;
                    } else {
                        ss -= C - 1 - x;
                        x = C - 1;
                    }
                }
                d ^= 1;
            }

            if (temp[ny][nx] != 0) {
                if (s[temp[ny][nx]].z < s[i].z) {
                    s[temp[ny][nx]].die = 1;
                    temp[ny][nx] = i;
                } else {
                    s[i].die = 1;
                }
            } else {
                temp[ny][nx] = i;
            }

            s[i].y = ny;
            s[i].x = nx;
            s[i].dir = d;
        }

        a = temp.clone();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        R = scanner.nextInt();
        C = scanner.nextInt();
        M = scanner.nextInt();
        for (int i = 1; i <= M; i++) {
            s[i] = new Shark();
            s[i].y = scanner.nextInt() - 1;
            s[i].x = scanner.nextInt() - 1;
            s[i].s = scanner.nextInt();
            s[i].dir = scanner.nextInt();
            s[i].z = scanner.nextInt();
            s[i].dir--;

            if (s[i].dir <= 1) {
                s[i].s %= 2 * (R - 1);
            } else {
                s[i].s %= 2 * (C - 1);
            }
            a[s[i].y][s[i].x] = i;
        }

        while (cur < C) {
            getShark();
            moveShark();
            cur++;
        }
        System.out.println(ret);
    }
}
