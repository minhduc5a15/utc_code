use std::io::{self, BufRead, Stdin};

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|line| line.unwrap());
    let line = lines.next().unwrap();
    let mut nm = line.split_whitespace();
    let n: usize = nm.next().unwrap().parse().unwrap();
    let m: i32 = nm.next().unwrap().parse().unwrap();
    let mut arr: Vec<i32> = lines.next().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut dp: Vec<i32> = vec![m + 1; (m + 1) as usize];
    arr.sort();
    dp[0] = 0;
    for i in 1..=m {
        for j in 0..n {
            if arr[j] <= i {
                dp[i as usize] = std::cmp::min(dp[i as usize], dp[(i - arr[j]) as usize] + 1);
            }
            else {
                break;
            }
        }
    }
    println!("{}", dp[m as usize]);
}