import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    private static long power(long base, long exponent, int modulus) {
        base %= modulus;
        long result = 1;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
            exponent >>= 1;
        }
        return result;
    }

    private static long comb(int n, int k) {
        if (k > n) return 0;
        long num = 1, deno = 1;
        for (int i = 0; i < k; ++i) {
            num = (num * (n - i)) % Main.MOD;
            deno = (deno * (i + 1)) % Main.MOD;
        }
        return (num * power(deno, Main.MOD - 2, Main.MOD)) % Main.MOD;
    }

    private static long solve(int n) {
        long res = 0;
        for (int k = 0; k <= n; ++k) {
            long p = power(2, power(2, k, MOD - 1), MOD);
            long term = (comb(n, k) * p) % MOD;
            if ((n - k) % 2 == 0) {
                res = (res + term) % MOD;
            } else {
                res = (res - term + MOD) % MOD;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(solve(n));
        scanner.close();
    }
}
