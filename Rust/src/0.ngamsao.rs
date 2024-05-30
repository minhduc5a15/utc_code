use std::io::{self, BufRead, Stdin};
use std::str::SplitWhitespace;

type Viii = Vec<Vec<Vec<i32>>>;

const MAXN: usize = 101;
const MAXC: usize = 11;

#[derive(Debug, Clone)]
struct Star {
    x: usize,
    y: usize,
    s: usize,
}

fn pre(c: usize, arr: &[Star], saved: &mut Viii, dp: &mut Viii) {
    for star in arr {
        for t in 0..=c {
            let bright = (star.s + t) % (c + 1);
            saved[t][star.x][star.y] += bright as i32;
        }
    }

    for t in 0..=c {
        for i in 1..MAXN {
            for j in 1..MAXN {
                dp[t][i][j] = saved[t][i][j] + dp[t][i - 1][j] + dp[t][i][j - 1] - dp[t][i - 1][j - 1];
            }
        }
    }
}

fn query(t: usize, x1: usize, y1: usize, x2: usize, y2: usize, c: usize, dp: &Viii) -> i32 {
    let t = t % (c + 1);
    dp[t][x2][y2] - if x1 > 0 { dp[t][x1 - 1][y2] } else { 0 } - if y1 > 0 { dp[t][x2][y1 - 1] } else { 0 } + if x1 > 0 && y1 > 0 { dp[t][x1 - 1][y1 - 1] } else { 0 }
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line: String = lines.next().unwrap().unwrap();
    let mut parts: SplitWhitespace = line.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let q: usize = parts.next().unwrap().parse().unwrap();
    let c: usize = parts.next().unwrap().parse().unwrap();

    let mut arr: Vec<Star> = Vec::with_capacity(n);
    for _ in 0..n {
        let line: String = lines.next().unwrap().unwrap();
        let mut parts = line.split_whitespace();
        let x: usize = parts.next().unwrap().parse().unwrap();
        let y: usize = parts.next().unwrap().parse().unwrap();
        let s: usize = parts.next().unwrap().parse().unwrap();
        arr.push(Star { x, y, s });
    }

    let mut saved: Viii = vec![vec![vec![0; MAXN]; MAXN]; MAXC];
    let mut dp: Viii = vec![vec![vec![0; MAXN]; MAXN]; MAXC];

    pre(c, &arr, &mut saved, &mut dp);

    for _ in 0..q {
        let line: String = lines.next().unwrap().unwrap();
        let mut parts: SplitWhitespace = line.split_whitespace();
        let t: usize = parts.next().unwrap().parse().unwrap();
        let x1: usize = parts.next().unwrap().parse().unwrap();
        let y1: usize = parts.next().unwrap().parse().unwrap();
        let x2: usize = parts.next().unwrap().parse().unwrap();
        let y2: usize = parts.next().unwrap().parse().unwrap();
        println!("{}", query(t, x1, y1, x2, y2, c, &dp));
    }
}
