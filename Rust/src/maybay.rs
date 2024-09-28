use std::io::{self, BufRead, Stdin};
use std::str::SplitWhitespace;

#[derive(Debug)]
struct State {
    start: i32,
    end: i32,
    val: i32,
}

fn search(arr: &Vec<State>, id: usize) -> isize {
    let mut low = 0;
    let mut high = id as isize - 1;
    while low <= high {
        let mid = (low + high) >> 1;
        if arr[mid as usize].end <= arr[id].start {
            if mid + 1 <= high && arr[mid as usize + 1].end <= arr[id].start {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|line| line.unwrap());
    let n: usize = lines.next().unwrap().trim().parse().unwrap();
    let mut arr: Vec<State> = Vec::with_capacity(n);
    for _ in 0..n {
        let line: String = lines.next().unwrap();
        let mut parts: SplitWhitespace = line.split_whitespace();
        let start: i32 = parts.next().unwrap().parse().unwrap();
        let end: i32 = parts.next().unwrap().parse().unwrap();
        let val: i32 = parts.next().unwrap().parse().unwrap();
        arr.push(State { start, end: start + end, val });
    }
    arr.sort_by(|a, b| a.end.cmp(&b.end));
    let mut dp: Vec<i32> = vec![0; n];
    dp[0] = arr[0].val;
    for i in 1..n {
        let val = arr[i].val;
        let l = search(&arr, i);
        let val = if l != -1 {
            val + dp[l as usize]
        } else {
            val
        };
        dp[i] = std::cmp::max(val, dp[i - 1]);
    }

    println!("{}", dp[n - 1]);
}
