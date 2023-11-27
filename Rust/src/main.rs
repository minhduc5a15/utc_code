#[warn(non_snake_case)]
#[warn(missing_docs)]
#[warn(unused_variables)]
#[warn(unused_imports)]
use std::collections::VecDeque;
use std::io::{self, BufRead};
type Matrix = Vec<Vec<bool>>;
const DIRECTIONS: [(i32, i32); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

fn main() {
    let stdin: io::Stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|line: Result<String, io::Error>| line.unwrap());
    if let Some(first_line) = lines.next() {
        let mut input_iter: std::str::SplitWhitespace<'_> = first_line.split_whitespace();
        let n: usize = input_iter.next().unwrap().parse().unwrap();
        let m: usize = input_iter.next().unwrap().parse().unwrap();
        let mut visited: Matrix = vec![vec![false; m]; n];
        let mut result: Matrix = vec![vec![false; m]; n];
        for i in 0..n {
            if let Some(line) = lines.next() {
                for (j, c) in line.chars().enumerate() {
                    visited[i][j] = c == '.';
                }
            }
        }
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();
        q.push_back((1, 1));
        result[1][1] = true;
        while let Some(pos) = q.pop_front() {
            for direction in &DIRECTIONS {
                let (nx, ny) = *direction;
                let mut count: i32 = 0;
                let mut steps: i32 = 0;
                loop {
                    let (x, y) = ((pos.0 as i32 + steps * nx), (pos.1 as i32 + steps * ny));
                    if x < 0 || x as usize >= n || y < 0 || y as usize >= m || !visited[x as usize][y as usize] {
                        break;
                    }
                    if !result[x as usize][y as usize] {
                        result[x as usize][y as usize] = true;
                        count += 1;
                    }
                    steps += 1;
                }
                if count != 0 {
                    q.push_back(((pos.0 as i32 + (steps - 1) * nx) as usize, (pos.1 as i32 + (steps - 1) * ny) as usize));
                }
            }
        }
        let mut count: i32 = 0;
        for i in 0..n {
            for j in 0..m {
                if result[i][j] {
                    count += 1;
                }
            }
        }
        println!("{}", count);
    }
}
