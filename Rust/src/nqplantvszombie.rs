use std::cmp::Reverse;
use std::collections::{BinaryHeap, VecDeque};
use std::io::{self, BufRead};

fn check(y: i64, n: usize, m: usize, x: usize, arr: &Vec<i32>) -> bool {
    let mut s: i64 = 0;
    let mut pq = BinaryHeap::new();
    let mut q: VecDeque<usize> = VecDeque::new();
    let mut die = vec![false; m];
    let mut i = 0;
    loop {
        if i < m {
            q.push_back(i);
        }
        while pq.len() < x && !q.is_empty() {
            let t = q.pop_front().unwrap();
            pq.push(Reverse((s + arr[t] as i64, t)));
        }
        s += y;
        while !pq.is_empty() && pq.peek().unwrap().0.0 <= s {
            let t = pq.pop().unwrap().0.1;
            die[t] = true;
        }
        i += 1;
        if i >= n {
            if !die[i - n] {
                return false;
            }
        }
        if i >= m {
            if pq.is_empty() && q.is_empty() {
                return true;
            }
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let first_line = lines.next().unwrap().unwrap();
    let mut iter = first_line.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    let x: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = Vec::with_capacity(m);
    let mut right = 0;
    if let Some(line) = lines.next() {
        for value in line.unwrap().split_whitespace() {
            let val: i32 = value.parse().unwrap();
            arr.push(val);
            right = right.max(val);
        }
    }
    let mut left = right / n as i32;
    while left <= right {
        let mid = left + (right - left) / 2;
        if check(mid as i64, n, m, x, &arr) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    println!("{}", left);
}