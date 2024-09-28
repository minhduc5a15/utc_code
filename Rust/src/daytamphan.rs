use std::io;

static mut COUNT: i32 = 0;
static mut N: usize = 0;
static mut ARR: Vec<i32> = Vec::new();

unsafe fn solve(m: usize) {
    if m == N {
        for i in 0..N {
            print!("{} ", ARR[i]);
        }
        println!();
        COUNT += 1;
        return;
    }
    for i in 0..=2 {
        ARR[m] = i;
        if m > 0 {
            if (i + ARR[m - 1]) % 3 == 0 || i == ARR[m - 1] {
                continue;
            }
        }
        solve(m + 1);
    }
}

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    unsafe {
        N = input.trim().parse().unwrap();
        ARR = vec![0; N];
        solve(0);
        println!("{}", COUNT);
    }
}
