use std::collections::HashMap;
use std::io::{self, BufRead};

const MAXN: usize = 1000001;

fn main() {
    let mut s: String = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let s: &str = s.trim();
    let mut map: HashMap<isize, usize> = HashMap::new();
    let mut k: isize = 0;
    let mut res: isize = -1;
    for (i, c) in s.chars().enumerate() {
        k += if c == 'X' { 1 } else { -1 };
        if k == 0 {
            res = res.max(i as isize + 1);
        } else {
            if let Some(&pos) = map.get(&(k + MAXN as isize)) {
                res = res.max((i - pos) as isize);
            }
            else {
                map.insert(k + MAXN as isize, i);
            }
        }
    }

    println!("{}", res);
}
