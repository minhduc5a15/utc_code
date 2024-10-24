use std::io::{self, BufRead};
use std::cmp::max;
use std::str::SplitWhitespace;

fn count(mut n: i64, p: i32) -> i32 {
    let mut res = 0;
    while n % p as i64 == 0 {
        res += 1;
        n /= p as i64;
    }
    res
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    for _ in 0..t {
        let line: String = lines.next().unwrap().unwrap();
        let mut split: SplitWhitespace = line.split_whitespace();
        let n: usize = split.next().unwrap().parse().unwrap();
        let k: usize = split.next().unwrap().parse().unwrap();
        let line: String = lines.next().unwrap().unwrap();
        let values: Vec<i64> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut pairs: Vec<(i32, i32)> = Vec::with_capacity(n);
        let mut five: i32 = 0;
        for &x in &values {
            let count2 = count(x, 2);
            let count5 = count(x, 5);
            pairs.push((count2, count5));
            five += count5;
        }
        let mut dp = vec![vec![-1; (five + 1) as usize]; k + 1];
        dp[0][0] = 0;
        for i in 0..n {
            let (first, second) = pairs[i];
            for j in (1..=k).rev() {
                for m in (second as usize..=(five as usize)).rev() {
                    if dp[j - 1][m - second as usize] != -1 {
                        dp[j][m] = max(dp[j][m], dp[j - 1][m - second as usize] + first);
                    }
                }
            }
        }
        let mut result = 0;
        for m in 0..=five as usize {
            if dp[k][m] != -1 {
                result = max(result, std::cmp::min(m as i32, dp[k][m]));
            }
        }
        println!("{}", result);
    }
}