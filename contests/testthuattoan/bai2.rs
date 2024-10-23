use std::io::{self, BufRead};
use std::cmp;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let arr: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut max_arr = vec![i32::MIN; n];
    max_arr[n - 1] = arr[n - 1];
    for i in (0..n - 1).rev() {
        max_arr[i] = cmp::max(max_arr[i + 1], arr[i]);
    }
    let mut max_val = i32::MIN;
    let mut res = i32::MIN;
    for j in 1..n - 1 {
        max_val = cmp::max(max_val, arr[j - 1]);
        res = cmp::max(res, max_val + max_arr[j + 1] - arr[j]);
    }
    println!("{}", res);
}