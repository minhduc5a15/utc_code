use std::cmp::min;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let x = lines.next().unwrap().unwrap();
    let y = lines.next().unwrap().unwrap();
    let n = x.len();
    let m = y.len();
    let mut dp = vec![vec![0; m + 1]; n + 1];
    for i in 0..=n {
        dp[i][0] = i;
    }
    for i in 0..=m {
        dp[0][i] = i;
    }
    for i in 1..=n {
        for j in 1..=m {
            if x.as_bytes()[i - 1] == y.as_bytes()[j - 1] {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    println!("{}", dp[n][m]);
}
