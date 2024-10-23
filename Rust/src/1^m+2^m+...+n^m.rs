use std::io::{self, BufRead};

const MOD: u64 = 1000000007;

fn power(mut base: u64, mut exponents: u64, modulus: u64) -> u64 {
    base %= modulus;
    let mut result: u64 = 1;
    while exponents > 0 {
        if exponents & 1 == 1 {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponents >>= 1;
    }
    result
}

fn inverse(n: u64, modulus: u64) -> u64 {
    power(n, modulus - 2, modulus)
}

fn precompute(m: u64) -> Vec<u64> {
    let mut result: Vec<u64> = vec![0; (m + 2) as usize];
    for i in 1..=m + 1 {
        let id: usize = i as usize;
        result[id] = (result[id - 1] + power(i, m, MOD)) % MOD;
    }
    result
}

fn solve(n: u64, m: u64) -> u64 {
    let pre: Vec<u64> = precompute(m);
    if n <= m + 1 {
        return pre[n as usize];
    }
    let (mut fact, mut inv_fact): (Vec<u64>, Vec<u64>) = (vec![1; (m + 2) as usize], vec![1; (m + 2) as usize]);
    for i in 2..=m + 1 {
        fact[i as usize] = (fact[i as usize - 1] * i) % MOD;
    }
    inv_fact[m as usize + 1] = inverse(fact[m as usize + 1], MOD);
    for i in (1..=m).rev() {
        inv_fact[i as usize] = (inv_fact[i as usize + 1] * (i + 1)) % MOD;
    }
    let (mut prefix, mut suffix): (Vec<u64>, Vec<u64>) = (vec![1; (m + 2) as usize], vec![1; (m + 2) as usize]);
    for i in 0..=m {
        prefix[i as usize + 1] = (prefix[i as usize] * (n - i)) % MOD;
    }
    for i in (1..=m + 1).rev() {
        suffix[i as usize - 1] = (suffix[i as usize] * (n - i)) % MOD;
    }
    let mut result: u64 = 0;
    for i in 0..=m + 1 {
        let mut term: u64 = pre[i as usize] * prefix[i as usize] % MOD * suffix[i as usize] % MOD;
        term = term * inv_fact[i as usize] % MOD * inv_fact[m as usize + 1 - i as usize] % MOD;
        if (m + 1 - i) & 1 == 1 {
            term = (MOD - term) % MOD;
        }
        result = (result + term) % MOD;
    }

    result
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line: String = lines.next().unwrap().unwrap();
    let mut parts = line.split_whitespace();
    let m: u64 = parts.next().unwrap().parse::<u64>().unwrap();
    let n: u64 = parts.next().unwrap().parse::<u64>().unwrap();
    println!("{}", solve(n, m));
}
