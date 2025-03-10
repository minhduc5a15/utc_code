use std::collections::HashMap;
use std::io;
use std::io::BufRead;

const MOD: u128 = 2000000000000000001;

fn mod_mul(a: u128, b: u128, m: u128) -> u128 {
    (a * b) % m
}

fn power(mut base: u128, mut exponents: u64, modulus: u128) -> u128 {
    let mut result = 1u128;
    while exponents > 0 {
        if exponents & 1 == 1 {
            result = mod_mul(result, base, modulus);
        }
        base = mod_mul(base, base, modulus);
        exponents >>= 1;
    }
    result
}

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    let mut i = 2;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 1;
    }
    true
}

fn divisors(f: &[(u64, u32)], i: usize, cur: u64, divs: &mut Vec<u64>) {
    if i == f.len() {
        divs.push(cur);
        return;
    }
    let (p, cnt) = f[i];
    let mut mult = 1;
    for _ in 0..=cnt {
        divisors(f, i + 1, cur * mult, divs);
        mult *= p;
    }
}

fn get_divisors(n: u64) -> Vec<u64> {
    let mut factors: Vec<(u64, u32)> = Vec::new();
    let mut temp = n;
    let mut i = 2;
    while i * i <= temp {
        if temp % i == 0 {
            let mut count = 0;
            while temp % i == 0 {
                count += 1;
                temp /= i;
            }
            factors.push((i, count));
        }
        i += 1;
    }
    if temp > 1 {
        factors.push((temp, 1));
    }
    let mut divs = Vec::new();
    divisors(&factors, 0, 1, &mut divs);
    divs
}

fn get_divisors_cached(n: u64, cache: &mut HashMap<u64, Vec<u64>>) -> Vec<u64> {
    if let Some(divs) = cache.get(&n) {
        return divs.clone();
    }
    let mut divs = get_divisors(n);
    divs.sort_by(|a, b| b.cmp(a));
    cache.insert(n, divs.clone());
    divs
}


fn dfs(
    i: usize,
    last: u64,
    cur_div: u64,
    cur_log: f64,
    cur_mod: u128,
    k: u64,
    primes: &Vec<u128>,
    saved: &mut (f64, u128),
    cache: &mut HashMap<u64, Vec<u64>>,
    memo: &mut HashMap<(usize, u64, u64), f64>,
) {
    let r = k / cur_div;
    let state = (i, r, last);
    if let Some(&min_log) = memo.get(&state) {
        if cur_log >= min_log {
            return;
        }
    }
    memo.insert(state, cur_log);

    if r == 1 {
        if cur_log < saved.0 {
            saved.0 = cur_log;
            saved.1 = cur_mod;
        }
        return;
    }
    if i >= primes.len() {
        return;
    }
    let divs = get_divisors_cached(r, cache);
    for &d in &divs {
        if d <= 1 {
            continue;
        }
        let e = d - 1;
        if e > last {
            continue;
        }
        let new_log = cur_log + (e as f64) * (primes[i] as f64).ln();
        if new_log >= saved.0 {
            continue;
        }
        let new_mod = mod_mul(cur_mod, power(primes[i], e, MOD), MOD);
        dfs(
            i + 1,
            e,
            cur_div * d,
            new_log,
            new_mod,
            k,
            primes,
            saved,
            cache,
            memo,
        );
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let k: u64 = lines.next().unwrap().unwrap().parse().unwrap();
    if is_prime(k) {
        println!("{}", power(2, k - 1, MOD));
        return;
    }
    let mut res = (((k - 1) as f64) * 2f64.ln(), power(2, k - 1, MOD));
    let primes: Vec<u128> = vec![
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
        97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    ];
    let mut cache: HashMap<u64, Vec<u64>> = HashMap::new();
    let mut memo: HashMap<(usize, u64, u64), f64> = HashMap::new();
    dfs(
        0,
        k,
        1,
        0.0,
        1,
        k,
        &primes,
        &mut res,
        &mut cache,
        &mut memo,
    );
    println!("{}", res.1);
}