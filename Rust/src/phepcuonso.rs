use std::cmp;
use std::io::{self, BufRead};

static mut RES: i64 = i64::MAX;

fn solve(s: &mut String) {
    let first = s.chars().next().unwrap().to_digit(10).unwrap() as i64;
    let last = s.chars().last().unwrap().to_digit(10).unwrap() as i64;
    if first + last > 9 || s.len() == 1 {
        unsafe {
            RES = cmp::min(RES, s.parse::<i64>().unwrap());
        }
        return;
    }
    let mid = &s[1..s.len() - 1];
    solve(&mut format!("{}{}", first + last, mid));
    solve(&mut format!("{}{}", mid, first + last));
}

fn main() {
    let stdin = io::stdin();
    let mut s = String::new();
    stdin.lock().read_line(&mut s).unwrap();
    s = s.trim().to_string();
    solve(&mut s);
    unsafe {
        println!("{}", RES);
    }
}
