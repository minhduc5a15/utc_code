use std::collections::HashMap;
use std::io::{self, BufRead};

fn solve(arr: &Vec<i64>, n: usize, k: i64) -> i64 {
    let mut map: HashMap<i64, i64> = HashMap::new();
    let (mut c, mut count, mut l, mut r) = (0, 0, 0, 0);
    while r < n {
        if *map.get(&arr[r]).unwrap_or(&0) == 0 {
            c += 1;
        }
        *map.entry(arr[r]).or_insert(0) += 1;
        while c > k {
            *map.get_mut(&arr[l]).unwrap() -= 1;
            if *map.get(&arr[l]).unwrap() == 0 {
                c -= 1;
            }
            l += 1;
        }
        count += (r - l + 1) as i64;
        r += 1;
    }

    count
}

fn main() {
    let stdin: io::Stdin = io::stdin();
    let mut input: String = String::new();
    stdin.lock().read_line(&mut input).unwrap();
    let mut parts: std::str::SplitWhitespace<'_> = input.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let k: i64 = parts.next().unwrap().parse().unwrap();

    input.clear();
    stdin.lock().read_line(&mut input).unwrap();
    let arr: Vec<i64> = input
        .split_whitespace()
        .map(|x: &str| x.parse().unwrap())
        .collect();

    println!("{}", solve(&arr, n, k));
}
