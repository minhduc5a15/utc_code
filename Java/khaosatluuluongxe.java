import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[] v_a = new int[m];
        long[] v_b = new long[m - 1];
        long[] v_c = new long[n];
        for (int i = 0; i < m; ++i) {
            v_a[i] = sc.nextInt();
        }
        for (int i = 0; i < m - 1; ++i) {
            v_b[i] = sc.nextLong();
        }
        for (int i = 0; i < n; ++i) {
            v_c[i] = sc.nextLong();
        }
        int [] res = new int[m];
        int i = 0, j = 0;
        long curr = v_a[0], sum = 0;
        Arrays.sort(v_c);
        while (j < m - 1) {
            if (curr >= v_b[j]) {
                curr -= v_b[j];
                curr += v_a[j + 1];
                ++j;
            } else {
                sum += v_b[j] - curr;
                while (i < n && v_c[i] < sum) {
                    ++i;
                    ++res[j];
                }
                curr = v_b[j];
            }
        }
        while (i < n) {
            ++i;
            ++res[j];
        }
        for (int r : res) {
            System.out.print(r + " ");
        }
    }
}
