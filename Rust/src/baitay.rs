use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();
    stdin.lock().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: i32 = iter.next().unwrap().parse().unwrap();
    let m: i32 = iter.next().unwrap().parse().unwrap();
    let k: i32 = iter.next().unwrap().parse().unwrap();
    let c = n / k;
    if m <= c {
        println!("{}", m);
    } else {
        println!("{}", c - ((m - c) + (k - 2)) / (k - 1));
    }
}
