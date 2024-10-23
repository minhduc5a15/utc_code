use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let s: String = lines.next().unwrap().unwrap();
    let mut mp = vec![0; 10];
    let mut sum = 0;
    let mut check = false;
    for c in s.chars() {
        let digit = c.to_digit(10).unwrap() as usize;
        if digit == 0 {
            check = true;
        }
        sum += digit;
        mp[digit] += 1;
    }
    if !check || sum % 9 != 0 {
        println!("-1");
        return;
    }
    for i in (0..=9).rev() {
        for _ in 0..mp[i] {
            print!("{}", i);
        }
    }
}
