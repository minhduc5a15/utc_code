use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let mut parts = line.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let w: i32 = parts.next().unwrap().parse().unwrap();
    let t: usize = parts.next().unwrap().parse().unwrap();
    let mut v: Vec<(i32, i32)> = vec![(0, 0); n];
    let line = lines.next().unwrap().unwrap();
    parts = line.split_whitespace();
    for i in 0..n {
        v[i].0 = parts.next().unwrap().parse().unwrap();
    }
    let mut curr = 0;
    let mut res = 0;
    let mut sum = 0;
    for i in 0..n {
        sum -= curr;
        curr -= v[i].1;
        if i >= t && v[i - t].0 > t as i32 {
            sum -= v[i - t].0 - t as i32;
        }
        sum += v[i].0;
        if sum < w && i >= t - 1 {
            let d = w - sum;
            res += d;
            v[i].0 += d;
            sum += d;
        }
        if v[i].0 > 0 {
            let next = std::cmp::min(v[i].0, t as i32) as usize + i;
            if next < n {
                v[next].1 += 1;
            }
            curr += 1;
        }
    }
    println!("{}", res);
}