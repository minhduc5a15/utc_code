use std::io::{self, BufRead, Stdin};

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line: String = lines.next().unwrap().unwrap();
    let mut nums = line.split_whitespace();
    let mut n: u32 = nums.next().unwrap().parse().unwrap();
    let mut k: u32 = nums.next().unwrap().parse().unwrap();
    n -= 1;
    k -= 1;
    println!("{}", n / k + if n % k == 0 { 0 } else { 1 });
}