use std::cmp::max;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut input = stdin.lock().lines();
    let t: usize = input.next().unwrap().unwrap().trim().parse().unwrap();

    for _ in 0..t {
        let n: usize = input.next().unwrap().unwrap().trim().parse().unwrap();
        let mut arr: Vec<(i64, i64)> = Vec::with_capacity(n);
        for _ in 0..n {
            let line = input.next().unwrap().unwrap();
            let mut parts = line.split_whitespace();
            let x: i64 = parts.next().unwrap().parse().unwrap();
            let r: i64 = parts.next().unwrap().parse().unwrap();
            arr.push((x, r));
        }
        arr.sort_by(|a, b| {
            let x1 = a.0 - a.1;
            let x2 = a.0 + a.1;
            let x3 = b.0 - b.1;
            let x4 = b.0 + b.1;
            if x1 == x3 {
                x2.cmp(&x4)
            } else {
                x1.cmp(&x3)
            }
        });
        let (mut x, mut y) = (arr[0].0 - arr[0].1, arr[0].0 + arr[0].1);
        let mut res: i64 = 0;

        for i in 1..n {
            if arr[i].0 - arr[i].1 > y {
                res += y - x;
                x = arr[i].0 - arr[i].1;
                y = arr[i].0 + arr[i].1;
            } else {
                y = max(y, arr[i].0 + arr[i].1);
            }
        }

        println!("{}", res - x + y);
    }
}
