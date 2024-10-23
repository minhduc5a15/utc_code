use std::io::{self, BufRead, Stdin};
use std::str::SplitWhitespace;

#[derive(Debug, Clone, Copy, PartialEq)]
struct Pair {
    b: i32,
    s: f64,
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|l| l.unwrap());
    let line: String = lines.next().unwrap();
    let mut parts: SplitWhitespace = line.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let mut v: f64 = parts.next().unwrap().parse().unwrap();
    let mut arr: Vec<Pair> = vec![Pair { b: 0, s: 0.0 }; n << 1];
    for i in 0..n {
        let line: String = lines.next().unwrap();
        let mut parts: SplitWhitespace = line.split_whitespace();
        let b: i32 = parts.next().unwrap().parse().unwrap();
        let h: f64 = parts.next().unwrap().parse().unwrap();
        let w: f64 = parts.next().unwrap().parse().unwrap();
        let d: f64 = parts.next().unwrap().parse().unwrap();
        arr[i << 1] = Pair { b, s: w * d };
        arr[i << 1 | 1] = Pair { b: b + h as i32, s: -w * d };
    }
    arr.sort_by(|a, b| a.b.cmp(&b.b));
    let mut curr_v = 0.0;
    let mut curr_h = 0;
    for i in 0..(n << 1) {
        if i > 0 && curr_v * (arr[i].b - curr_h) as f64 >= v {
            return println!("{:.2}", curr_h as f64 + v / curr_v);
        }
        v -= (arr[i].b - curr_h) as f64 * curr_v * if i > 0 { 1.0 } else { 0.0 };
        curr_h = arr[i].b;
        curr_v += arr[i].s;
    }
    println!("{:.2}", curr_h as f64 + v / curr_v);
}
