use std::cmp::Reverse;
use std::collections::{BinaryHeap};
use std::io::{self, BufRead};

struct DSU {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl DSU {
    fn new(n: usize) -> Self {
        let mut parent = vec![0; n + 1];
        let rank = vec![1; n + 1];
        for i in 1..=n {
            parent[i] = i;
        }
        Self { parent, rank }
    }

    fn find(&mut self, u: usize) -> usize {
        if self.parent[u] != u {
            self.parent[u] = self.find(self.parent[u]);
        }
        self.parent[u]
    }

    fn unite(&mut self, u: usize, v: usize) -> bool {
        let mut u = self.find(u);
        let mut v = self.find(v);
        if u == v {
            return false;
        }
        if self.rank[u] < self.rank[v] {
            std::mem::swap(&mut u, &mut v);
        }
        self.parent[v] = u;
        self.rank[u] += self.rank[v];
        true
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let first_line = lines.next().unwrap().unwrap();
    let mut iter = first_line.split_whitespace().map(|s| s.parse::<usize>().unwrap());
    let (n, m, k) = (iter.next().unwrap(), iter.next().unwrap(), iter.next().unwrap());

    let mut weights = vec![0i64; n];
    let second_line = lines.next().unwrap().unwrap();
    for (i, w) in second_line.split_whitespace().enumerate() {
        weights[i] = w.parse().unwrap();
    }

    let mut dsu = DSU::new(n);
    let mut edges = Vec::with_capacity(m);

    for _ in 0..m {
        let line = lines.next().unwrap().unwrap();
        let mut it = line.split_whitespace().map(|s| s.parse::<usize>().unwrap());
        let (u, v) = (it.next().unwrap(), it.next().unwrap());
        edges.push((u, v));
        dsu.unite(u, v);
    }

    let mut components = vec![Vec::new(); n + 1];
    for u in 1..=n {
        components[dsu.find(u)].push(u);
    }

    let mut step1_cost = 0;
    let mut min_weights = Vec::new();
    let mut mst_edges = Vec::new();
    let mut edge_list = vec![Vec::new(); n + 1];

    for &(u, v) in &edges {
        let root = dsu.find(u);
        edge_list[root].push((-weights[u - 1] - weights[v - 1], u, v));
    }

    let mut s_initial = 0;
    for root in 1..=n {
        if components[root].is_empty() {
            continue;
        }
        s_initial += 1;
        if !edge_list[root].is_empty() {
            let mut sum_component = 0;
            let mut sum_mst = 0;
            let mut sorted_edges = edge_list[root].clone();
            sorted_edges.sort();
            let mut d = DSU::new(n);
            for &(w, u, v) in &sorted_edges {
                let w_e = -w;
                sum_component += w_e;
                if d.unite(u, v) {
                    sum_mst += w_e;
                    mst_edges.push(w_e);
                }
            }
            step1_cost += sum_component - sum_mst;
        }
        let min_w = components[root].iter().map(|&u| weights[u - 1]).min().unwrap();
        min_weights.push(min_w);
    }

    let mut res = step1_cost;
    if s_initial > k {
        let mut pq = BinaryHeap::from(min_weights.iter().map(|&w| Reverse(w)).collect::<Vec<_>>());
        let mut merge_cost = 0;
        for _ in 0..s_initial - k {
            let a = pq.pop().unwrap().0;
            let b = pq.pop().unwrap().0;
            merge_cost += a + b;
            pq.push(Reverse(a.min(b)));
        }
        res += merge_cost;
    }
    println!("{}", res);
}
