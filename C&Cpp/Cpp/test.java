import java.util.LinkedList;
import java.util.Scanner;

public class Problem1282 {
    public static String[] F;
    public static long[] f;

    public static void precomputeF(long M) {
        F = new String[101];
        F[0] = "0";
        F[1] = "1";
        for (int i = 1; i < 3 || F[i - 3].length() < M; i++) {
            F[i + 1] = F[i] + F[i - 1];
        }
    }

    public static void precomputef(int M) {
        f = new long[M + 1];
        f[0] = 1;
        f[1] = 1;

        for (int i = 1; i < M; i++) {
            f[i + 1] = f[i] + f[i - 1];
        }
    }

    public static long occurrences(int n, String p) {
        if (p.equals("0")) {
            if (n < 2) {
                return n == 0 ? 1 : 0;
            }
            return f[n - 2];
        }
        if (p.equals("1")) {
            if (n < 2) {
                return n == 0 ? 0 : 1;
            }
            return f[n - 1];
        }

        int m = 3;
        while (f[m - 3] <= p.length()) {
            m++;
        }

        if (m > n) {
            m = n;
        }

        long a = 0;
        long b = 0;
        long[] o = new long[2];

        LinkedList<Integer> occurrences = KMP.search(F[m], p, (int) f[m - 1]);
        for (int found : occurrences) {
            if (found < f[m - 2]) {
                if (found + p.length() - 1 < f[m - 2]) {
                    b++;
                } else {
                    o[0]++;
                }
            } else if (found < f[m - 1]) {
                if (found + p.length() - 1 < f[m - 1]) {
                    a++;
                } else {
                    o[1]++;
                }
            }
        }

        int i;
        for (i = 0; i <= n - m + 1; i++) {
            long old_b = b;
            b = b + a + o[i % 2];
            a = old_b;
        }

        return b;
    }

    public static void main(String[] args) {
        precomputeF(100000);
        precomputef(100);

        java.util.Scanner scanner = new Scanner(System.in);
        for (int c = 1; scanner.hasNext(); c++) {
            int n = Integer.parseInt(scanner.nextLine());
            String p = scanner.nextLine();
            System.out.format("Case %d: %d\n", c, occurrences(n, p));
        }
    }
}

class KMP {
    private static int[] borderArray(String s) {
        char[] x = s.toCharArray();
        int n = x.length;
        int[] beta = new int[n];
        int b = 0;
        for (int i = 1; i < n; i++) {
            while (b > 0 && x[i] != x[b]) {
                b = beta[b - 1];
            }
            beta[i] = b = (x[i] == x[b] ? b + 1 : 0);
        }
        return beta;
    }

    public static LinkedList<Integer> search(String xx, String pp, int max_index) {
        char[] x = xx.toCharArray();
        char[] p = pp.toCharArray();
        int[] beta = borderArray(pp);
        int i = 0, m = 0;
        LinkedList<Integer> results = new LinkedList<Integer>();
        while (m + i < x.length) {
            if (m > max_index) {
                break;
            }
            if (x[m + i] == p[i]) {
                if (i == p.length - 1) {
                    results.add(m);
                } else {
                    i++;
                    continue;
                }
            }
            if (i > 0) {
                m = m + i - beta[i - 1];
                i = beta[i - 1];
            } else {
                m = m + 1;
                i = 0;
            }
        }

        return results;
    }
}