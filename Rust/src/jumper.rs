use std::collections::VecDeque;
use std::io::{self, BufRead, Stdin};
use std::str::SplitWhitespace;

const MAXN: i32 = 100;

#[derive(Clone, Copy)]
struct Pii {
    x: i32,
    y: i32,
}

fn is_valid(x: i32, y: i32) -> bool {
    -MAXN <= x && x <= MAXN && -MAXN <= y && y <= MAXN
}

fn solve(start: Pii, end: Pii, jumper: Pii, max_steps: i32) -> i32 {
    let dx = vec![jumper.x, jumper.x, -jumper.x, -jumper.x, jumper.y, jumper.y, -jumper.y, -jumper.y];
    let dy = vec![jumper.y, -jumper.y, jumper.y, -jumper.y, jumper.x, -jumper.x, jumper.x, -jumper.x];
    let mut visited = vec![vec![false; 2 * MAXN as usize + 5]; 2 * MAXN as usize + 5];
    visited[(start.x + MAXN) as usize][(start.y + MAXN) as usize] = true;
    let mut q = VecDeque::new();
    q.push_back((start.x, start.y, 0));
    while let Some((x, y, steps)) = q.pop_front() {
        if steps > max_steps {
            return -1;
        }
        if x == end.x && y == end.y {
            return steps;
        }
        for i in 0..8 {
            let nx = x + dx[i];
            let ny = y + dy[i];
            if is_valid(nx, ny) && !visited[(nx + MAXN) as usize][(ny + MAXN) as usize] {
                q.push_back((nx, ny, steps + 1));
                visited[(nx + MAXN) as usize][(ny + MAXN) as usize] = true;
            }
        }
    }
    -1
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    let mut jumper: Pii = Pii { x: 0, y: 0 };
    let mut start: Pii = Pii { x: 0, y: 0 };
    let mut end: Pii = Pii { x: 0, y: 0 };
    let mut k: i32;
    for _ in 0..t {
        {
            let line: String = lines.next().unwrap().unwrap();
            let mut parts: SplitWhitespace = line.trim().split_whitespace();
            jumper.x = parts.next().unwrap().parse().unwrap();
            jumper.y = parts.next().unwrap().parse().unwrap();
        }
        {
            let line: String = lines.next().unwrap().unwrap();
            let mut parts: SplitWhitespace = line.trim().split_whitespace();
            start.x = parts.next().unwrap().parse().unwrap();
            start.y = parts.next().unwrap().parse().unwrap();
        }
        {
            let line: String = lines.next().unwrap().unwrap();
            let mut parts: SplitWhitespace = line.trim().split_whitespace();
            end.x = parts.next().unwrap().parse().unwrap();
            end.y = parts.next().unwrap().parse().unwrap();
        }
        k = lines.next().unwrap().unwrap().parse().unwrap();
        let res: i32 = solve(start, end, jumper, k);
        if res == -1 {
            println!("NO");
        } else {
            println!("{}", res);
        }
    }
}
