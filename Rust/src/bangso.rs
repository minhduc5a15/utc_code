use std::io::{self, BufRead};

fn solve(matrix: Vec<Vec<i32>>) -> i32 {
    let m = matrix.len();
    let n = matrix[0].len();
    let mut dp = vec![vec![0; n]; m];
    dp[0][0] = matrix[0][0];
    for i in 1..m {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }
    for j in 1..n {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }
    for i in 1..m {
        for j in 1..n {
            dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]) + matrix[i][j];
        }
    }
    dp[m - 1][n - 1]
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let m = line.split_whitespace().next().unwrap().parse().unwrap();
    let mut matrix = Vec::with_capacity(m);
    for _ in 0..m {
        let line = lines.next().unwrap().unwrap();
        let row: Vec<i32> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();
        matrix.push(row);
    }
    println!("{}", solve(matrix));
}
