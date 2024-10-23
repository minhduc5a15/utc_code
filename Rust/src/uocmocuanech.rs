use std::io::{stdin, BufRead};

fn main() {
    let stdin = stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let mut nq = line.split_whitespace();
    let n: usize = nq.next().unwrap().parse().unwrap();
    let q: usize = nq.next().unwrap().parse().unwrap();
    let mut res = vec![0; n + 1];
    let mut next = vec![-1; n + 1];
    let mut arr = vec![0; n + 1];
    let line = lines.next().unwrap().unwrap();
    let mut values = line.split_whitespace();
    for i in 1..=n {
        arr[i] = values.next().unwrap().parse().unwrap();
    }
    let mut st: Vec<usize> = Vec::new();
    for i in (1..=n).rev() {
        while !st.is_empty() && arr[*st.last().unwrap()] <= arr[i] {
            st.pop();
        }
        if let Some(&top) = st.last() {
            next[i] = top as i32;
            res[i] = res[top] + 1;
        }
        st.push(i);
    }
    for _ in 0..q {
        let x: usize = lines.next().unwrap().unwrap().parse().unwrap();
        println!("{}", res[x]);
    }
}