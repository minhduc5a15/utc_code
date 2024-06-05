use std::io::{self, Stdin, BufRead};
use std::str::SplitWhitespace;
use std::cmp;

const MOD: i64 = 1_000_000_007;

fn coe(n: i64, k: i64, m: i64) -> i64 {
    if k > n || k < 0 {
        return 0;
    }
    if k == 0 || k == n {
        return 1;
    }
    let k: i64 = k.min(n - k);
    let mut c: Vec<i64> = vec![0; k as usize + 1];
    c[0] = 1;
    for i in 1..=n {
        for j in (1..=cmp::min(k, i)).rev() {
            c[j as usize] = (c[j as usize] + c[j as usize - 1]) % m;
        }
    }
    c[k as usize]
}

fn solve(n: i64, a: i64, s: i64, b: i64) -> i64 {
    let max_b: i64 = a;
    let min_b: i64 = b;
    let total: i64 = s;
    if n * min_b > total || total > n * max_b {
        return 0;
    }
    let m: i64 = total - n * min_b;
    let k: i64 = max_b - min_b;
    let mut result = 0;
    for i in 0..=n {
        let s: i64 = if i % 2 == 0 { 1 } else { -1 };
        let t: i64 = (coe(n, i, MOD) * coe(m - i * (k + 1) + n - 1, n - 1, MOD)) % MOD;
        result = (result + s * t + MOD) % MOD;
    }
    result
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line: String = lines.next().unwrap().unwrap();
    let mut parts: SplitWhitespace = line.split_whitespace();
    let n: i64 = parts.next().unwrap().parse().unwrap();
    let a: i64 = parts.next().unwrap().parse().unwrap();
    let s: i64 = parts.next().unwrap().parse().unwrap();
    let b: i64 = parts.next().unwrap().parse().unwrap();
    println!("{}", solve(n, a, s, b));
}
