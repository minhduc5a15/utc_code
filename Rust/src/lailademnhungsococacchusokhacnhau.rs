use std::io::{self, BufRead};

const MAXN: i64 = 9876543210;

fn perm(n: i64, r: i64) -> i64 {
    let mut res = 1;
    for i in (n - r + 1)..=n {
        res *= i;
    }
    res
}

fn count(n: i64) -> i64 {
    let mut nums = [0; 20];
    let mut k = 0;
    let mut n = n + 1;
    while n > 0 {
        nums[k] = (n % 10) as usize;
        n /= 10;
        k += 1;
    }
    nums[0..k].reverse();
    let mut res = 0;
    for i in 1..k {
        res += 9 * perm(9, (i - 1) as i64);
    }
    for i in 0..k {
        let x = nums[i];
        for y in if i == 0 { 1 } else { 0 }..x {
            let mut found = false;
            for j in 0..i {
                if nums[j] == y {
                    found = true;
                    break;
                }
            }
            if !found { res += perm(9 - i as i64, k as i64 - i as i64 - 1); }
        }
        let mut found = false;
        for j in 0..i {
            if nums[j] == x {
                found = true;
                break;
            }
        }
        if found { break; }
    }
    return res;
}

fn solve(l: i64, r: i64) -> i64 {
    return count(if r < MAXN { r } else { MAXN }) - count(if l > 1 { l - 1 } else { 0 }) + if l == 0 { 1 } else { 0 };
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<&str> = line.split_whitespace().collect();
        let l: i64 = parts[0].parse().unwrap();
        let r: i64 = parts[1].parse().unwrap();
        println!("{}", solve(l, r));
    }
}
