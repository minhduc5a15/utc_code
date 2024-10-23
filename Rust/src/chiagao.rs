use std::cmp::{max, min};
use std::io;

static mut ARR: Vec<i32> = Vec::new();
static mut RES: i32 = i32::MAX;

unsafe fn solve(a: i32, b: i32, c: i32, steps: usize, c1: i32, c2: i32, c3: i32) {
    if c1 > 3 || c2 > 3 || c3 > 3 { return; }
    if steps == 9 {
        RES = min(RES, max(max(a, b), c) - min(min(a, b), c));
        return;
    }
    solve(a + ARR[steps], b, c, steps + 1, c1 + 1, c2, c3);
    solve(a, b + ARR[steps], c, steps + 1, c1, c2 + 1, c3);
    solve(a, b, c + ARR[steps], steps + 1, c1, c2, c3 + 1);
}

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    unsafe {
        ARR = input.split_whitespace().map(|x| x.parse().expect("")).collect();
        solve(0, 0, 0, 0, 0, 0, 0);
        println!("{}", RES);
    }
}
