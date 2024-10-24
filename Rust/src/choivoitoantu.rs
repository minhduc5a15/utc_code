use std::io;
use std::io::{BufRead, Stdin};
use std::str::SplitWhitespace;

fn solve(x: i32, y: i32) -> i32 {
    let mut z = x ^ y;
    let mut i = 0;
    while z != 0 {
        if z & 1 != 0 {
            return 1 << i;
        }
        i += 1;
        z >>= 1;
    }
    1 << i
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let line: String = lines.next().unwrap().unwrap();
        let mut nums: SplitWhitespace = line.split_whitespace();
        let x: i32 = nums.next().unwrap().parse().unwrap();
        let y: i32 = nums.next().unwrap().parse().unwrap();
        println!("{}", solve(x, y));
    }
}
