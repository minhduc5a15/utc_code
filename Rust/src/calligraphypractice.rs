use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut bit = vec![0; n];
    for i in 0..n {
        let s = lines.next().unwrap().unwrap();
        for c in s.chars() {
            bit[i] |= 1 << (c as u32 - 'a' as u32);
        }
    }
    let all = (1 << 26) - 1;
    let mut res = 0;
    for i in 0..(1 << n) {
        let mut comb = 0;
        for j in 0..n {
            if i & (1 << j) != 0 {
                comb |= bit[j];
            }
        }
        if comb == all {
            res += 1;
        }
    }
    println!("{}", res);
}
