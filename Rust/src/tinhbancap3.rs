use std::cmp;
use std::collections::HashMap;

type Pii = (i32, i32);
type Vi = Vec<i32>;

fn dfs(steps: i32, start: i32, u: i32, adj: &Vec<Vi>, mp: &mut HashMap<Pii, i32>) {
    if steps == 3 {
        let key: (i32, i32) = (cmp::min(u, start), cmp::max(u, start));
        let count = mp.entry(key).or_insert(0);
        *count += 1;
        return;
    }
    for &v in &adj[u as usize] {
        dfs(steps + 1, start, v, adj, mp);
    }
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.trim().split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut adj: Vec<Vi> = vec![vec![]; n + 1];
    for _ in 0..m {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.trim().split_whitespace();
        let u: i32 = iter.next().unwrap().parse().unwrap();
        let v: i32 = iter.next().unwrap().parse().unwrap();
        adj[u as usize].push(v);
        adj[v as usize].push(u);
    }

    for _ in 0..k {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let x: i32 = input.trim().parse().unwrap();
        let mut mp: HashMap<Pii, i32> = HashMap::new();
        bt(0, x, x, &adj, &mut mp);
        println!("{}", mp.len());
    }
}
