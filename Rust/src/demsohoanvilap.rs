use std::io::{self, BufRead};
use std::collections::HashMap;

const MOD: i64 = 1_000_000_007;
const MAXN: usize = 100_001;

fn power(mut base: i64, mut exponent: i64, modulus: i64) -> i64 {
    base %= modulus;
    let mut result: i64 = 1;
    while exponent > 0 {
        if exponent & 1 == 1 {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    result
}

fn inverse_pow(n: i64) -> i64 {
    power(n, MOD - 2, MOD)
}

fn c(n: usize, r: usize, factorial: &Vec<i64>, inverse: &Vec<i64>) -> i64 {
    if r > n {
        return 0;
    }
    (factorial[n] * ((inverse[r] * inverse[n - r]) % MOD)) % MOD
}

fn init() -> (Vec<i64>, Vec<i64>) {
    let mut factorial = vec![0; MAXN + 1];
    let mut inverse = vec![0; MAXN + 1];
    factorial[0] = 1;
    inverse[0] = 1;
    for i in 1..=MAXN {
        factorial[i] = (factorial[i - 1] * i as i64) % MOD;
        inverse[i] = inverse_pow(factorial[i]);
    }
    (factorial, inverse)
}

fn solve(s: &str, factorial: &Vec<i64>, inverse: &Vec<i64>) -> i64 {
    let mut mp = HashMap::new();
    for ch in s.chars() {
        *mp.entry(ch).or_insert(0) += 1;
    }
    let mut n = s.len();
    let mut res: i64 = 1;
    for &count in mp.values() {
        res *= c(n, count, factorial, inverse);
        res %= MOD;
        n -= count;
    }
    res % MOD
}

fn main() {
    let (factorial, inverse) = init();
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let s = lines.next().unwrap().unwrap();
        println!("{}", solve(&s, &factorial, &inverse));
    }
}
