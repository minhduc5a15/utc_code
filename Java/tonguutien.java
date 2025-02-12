import java.util.*;
import java.io.*;

public class minhduc5a12 {
    private static final int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        int max_n = Math.max(m, Math.max(n, p));

        long[] v_a = new long[max_n + 1];
        long[] v_b = new long[max_n + 1];
        long[] v_c = new long[max_n + 1];
        long[] prefix_a = new long[max_n + 1];
        long[] prefix_b = new long[max_n + 1];
        long[] prefix_c = new long[max_n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= m; ++i) {
            v_a[i] = Long.parseLong(st.nextToken()) % MOD;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            v_b[i] = Long.parseLong(st.nextToken()) % MOD;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= p; ++i) {
            v_c[i] = Long.parseLong(st.nextToken()) % MOD;
        }

        long curr = 0;
        for (int i = 1; i <= max_n; ++i) {
            curr = (curr + v_a[i]) % MOD;
            prefix_a[i] = curr;
        }

        curr = 0;
        for (int i = 1; i <= max_n; ++i) {
            curr = (curr + v_b[i]) % MOD;
            prefix_b[i] = curr;
        }

        curr = 0;
        for (int i = 1; i <= max_n; ++i) {
            curr = (curr + v_c[i]) % MOD;
            prefix_c[i] = curr;
        }

        long res = 0;
        for (int i = 1; i <= max_n; ++i) {
            long prev = (((prefix_a[i - 1] % MOD) * prefix_b[i - 1]) % MOD) * prefix_c[i - 1] % MOD;
            curr = ((prefix_a[i] * prefix_b[i]) % MOD) * prefix_c[i] % MOD;
            long diff = (curr - prev + MOD) % MOD;
            long term = (diff * i) % MOD;
            res = (res + term) % MOD;
        }

        System.out.println(res);
    }
}
