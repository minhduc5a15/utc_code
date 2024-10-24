use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::io;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: i64,
    position: usize,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut vals = vec![0; n + 1];
    let mut costs = vec![vec![0; n + 1]; n + 1];
    let mut graph = vec![vec![]; n + 1];
    let mut saved = vec![0; n + 1];
    let mut visited = vec![false; n + 1];

    for i in 1..=n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        vals[i] = input.trim().parse().unwrap();
    }

    for i in 1..=n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let cost_row: Vec<i64> = input.trim().split_whitespace().map(|num| num.parse().unwrap()).collect();
        for j in 1..=n {
            costs[i][j] = cost_row[j - 1];
            graph[i].push((costs[i][j], j));
            graph[j].push((costs[i][j], i));
        }
    }

    let mut heap = BinaryHeap::new();
    for i in 1..=n {
        saved[i] = vals[i];
        heap.push(State { cost: saved[i], position: i });
    }

    while let Some(State { cost: _, position: u }) = heap.pop() {
        if visited[u] { continue; }
        visited[u] = true;
        for &(next_cost, v) in &graph[u] {
            if visited[v] || saved[v] <= next_cost { continue; }
            saved[v] = next_cost;
            heap.push(State { cost: saved[v], position: v });
        }
    }

    let res: i64 = saved.iter().sum();
    print!("{}", res);
}
