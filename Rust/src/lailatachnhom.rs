use std::str::SplitWhitespace;

static mut COUNT: i32 = 0;

unsafe fn solve(n: i32, k: i32) {
    if n < k + 2 || (n - k) & 1 != 0 {
        COUNT += 1;
        return;
    }
    solve((n + k) >> 1, k);
    solve((n - k) >> 1, k);
}

fn main() {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut parts: SplitWhitespace = input.trim().split_whitespace();
    let n: i32 = parts.next().unwrap().parse().unwrap();
    let k: i32 = parts.next().unwrap().parse().unwrap();
    if n == k {
        return print!("1");
    }
    if n < k + 2 {
        return print!("0");
    }
    unsafe {
        solve(n, k);
        return print!("{}", COUNT);
    }
}