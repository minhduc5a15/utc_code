use std::io::{self, BufRead, Stdin};
use std::collections::VecDeque;
use std::cmp::min;

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let _n: usize = lines.next().unwrap().unwrap().parse().unwrap();
        let mut st: VecDeque<(i32, usize)> = VecDeque::new();
        {
            let x_values: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
            for (i, &x) in x_values.iter().enumerate() {
                if st.is_empty() || st.back().unwrap().0 > x {
                    st.push_back((x, i));
                }
            }
        }
        let mut res: i32 = i32::MAX;
        {
            let y_values: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
            for (i, &y) in y_values.iter().enumerate() {
                if st.is_empty() || i > res as usize { continue; }
                while !st.is_empty() && st.back().unwrap().0 < y {
                    res = min(res, (st.back().unwrap().1 + i) as i32);
                    st.pop_back();
                }
            }
        }
        println!("{}", res);
    }
}
