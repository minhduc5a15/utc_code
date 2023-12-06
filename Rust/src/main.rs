use std::collections::{HashMap, VecDeque};
use std::io::{self, BufRead};

fn solve(n: usize, adj_list: &Vec<Vec<usize>>) {
    let mut q = VecDeque::new();
    let mut map = HashMap::new();
    let mut dist = vec![-1isize; n + 1];
    let stdin = io::stdin();
    let mut it = stdin.lock().lines();
    let t: usize = it.next().unwrap().unwrap().parse().unwrap();
    map.insert(0, t);
    for _ in 0..t {
        let node: usize = it.next().unwrap().unwrap().parse().unwrap();
        q.push_back(node);
        dist[node] = 0;
    }
    while let Some(u) = q.pop_front() {
        for &v in &adj_list[u] {
            if dist[v] == -1 {
                q.push_back(v);
                dist[v] = dist[u] + 1;
                *map.entry(dist[v] as usize).or_insert(0) += 1;
            }
        }
    }

    for i in 0..n {
        if let Some(&count) = map.get(&i) {
            println!("F{}: {}", i, count);
        } else {
            break;
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut it = stdin.lock().lines();
    let nm: Vec<usize> = it.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let (n, m) = (nm[0], nm[1]);
    let mut adj_list = vec![vec![]; n + 1];
    for _ in 0..m {
        let uv: Vec<usize> = it.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let (u, v) = (uv[0], uv[1]);
        adj_list[u].push(v);
        adj_list[v].push(u);
    }
    solve(n, &adj_list);
}
