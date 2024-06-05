use std::io::{self, BufRead};

fn main() {
    let stdin: io::Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line: String = lines.next().unwrap().unwrap();
    let mut parts = line.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let k: usize = parts.next().unwrap().parse().unwrap();
    let mut arr: Vec<i64> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    arr.sort();
    let mut res: i64 = i64::MAX;
    for i in 0..=n - k {
        let mut curr = arr[i + k - 1] - arr[i];
        let l = arr[i].abs();
        let r = arr[i + k - 1].abs();
        curr += l.min(r);
        res = res.min(curr);
    }
    println!("{}", res);
}