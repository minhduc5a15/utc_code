static mut COUNT: i32 = 0;

unsafe fn solve(n: i32) {
    if n < 6 || n & 1 != 0 {
        COUNT += 1;
        return;
    }
    solve((n + 4) >> 1);
    solve((n - 4) >> 1);
}

fn main() {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    if n == 4 {
        return print!("1");
    }
    if n < 6 {
        return print!("0");
    }
    unsafe {
        solve(n);
        return print!("{}", COUNT);
    }
}