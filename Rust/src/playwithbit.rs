use std::io::{self, BufRead};
use std::collections::HashMap;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    let mut arr: Vec<i64>;
    let mut saved: Vec<i64>;
    let mut mp: HashMap<i64, i32>;
    for _ in 0..t {
        let nk: Vec<i64> = lines.next().unwrap().unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let (n, k) = (nk[0], nk[1]);
        arr = vec![0; n as usize];
        saved = vec![-1; n as usize];
        mp = HashMap::new();
        let x_values: Vec<i64> = lines.next().unwrap().unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        for i in 0..n as usize {
            let x = x_values[i];
            if x > k { continue; }
            saved[i] = x ^ (k - x);
            arr[i] = x;
            *mp.entry(x).or_insert(0) += 1;
        }
        let mut res = 0;
        for i in 0..n as usize {
            *mp.get_mut(&arr[i]).unwrap() -= 1;
            res += *mp.get(&saved[i]).unwrap_or(&0);
        }
        println!("{}", res);
    }
}
