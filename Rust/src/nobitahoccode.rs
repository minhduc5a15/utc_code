use std::cmp;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let mut split = line.split_whitespace();
    let n: usize = split.next().unwrap().parse().unwrap();
    let k: usize = split.next().unwrap().parse().unwrap();
    let mut s = 0;
    let mut res = 0;
    let mut mp = vec![0; k + 1];
    for i in 0..n {
        let line = lines.next().unwrap().unwrap();
        let x: usize = line.parse().unwrap();
        s = (s + x) % k;
        if s == 0 {
            res = i + 1;
        } else if mp[s] == 0 {
            mp[s] = i + 1;
        } else {
            res = cmp::max(res, i + 1 - mp[s]);
        }
    }
    println!("{}", res);
}
