use std::io::{self, BufRead};

fn solve(arr: Vec<i32>, n: usize) -> i32 {
    let mut arr_pos: Vec<(i32, usize)> = arr.iter().enumerate().map(|(i, &val)| (val, i)).collect();
    arr_pos.sort();
    let mut visited = vec![false; n];
    let mut res = 0;
    for i in 0..n {
        if visited[i] || arr_pos[i].1 == i {
            continue;
        }
        let mut cycle_size = 0;
        let mut j = i;
        while !visited[j] {
            visited[j] = true;
            j = arr_pos[j].1;
            cycle_size += 1;
        }
        if cycle_size > 0 {
            res += cycle_size - 1;
        }
    }
    res
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|line| line.unwrap());
    let n: usize = lines.next().unwrap().trim().parse().unwrap();
    let mut arr: Vec<i32> = lines
        .next()
        .unwrap()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let steps_1 = solve(arr.clone(), n);
    arr.reverse();
    let steps_2 = solve(arr.clone(), n);

    println!("{}", std::cmp::min(steps_1, steps_2));
}
