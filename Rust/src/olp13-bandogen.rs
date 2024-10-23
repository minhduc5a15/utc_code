use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let nk: Vec<usize> = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, k) = (nk[0], nk[1]);
    let mut mp1: HashMap<String, i64> = HashMap::new();
    let mut mp2: HashMap<String, i64> = HashMap::new();
    for _ in 0..n {
        let s = lines.next().unwrap().unwrap();
        let sz = s.len();
        if sz >= k {
            let subs = format!("{}{}", &s[0..k], &s[sz - k..sz]);
            *mp1.entry(subs).or_insert(0) += 1;
        }
        if sz >= k + 1 {
            let subs = format!("{}{}", &s[0..k + 1], &s[sz - k - 1..sz]);
            *mp2.entry(subs).or_insert(0) += 1;
        }
    }
    let mut res: i64 = 0;
    for (_, &v) in &mp1 {
        if v > 1 {
            res += v * (v - 1) / 2;
        }
    }
    for (_, &v) in &mp2 {
        if v > 1 {
            res -= v * (v - 1) / 2;
        }
    }
    println!("{}", res);
}
