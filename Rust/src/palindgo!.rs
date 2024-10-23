use std::collections::HashSet;
use std::io::{self, BufRead, Lines, Stdin, StdinLock};

const DX: [usize; 2] = [1, 0];
const DY: [usize; 2] = [0, 1];

#[derive(Clone)]
struct State {
    x: usize,
    y: usize,
    current: String
}

fn is_valid(x: usize, y: usize, n: usize) -> bool {
    x < n && y < n
}

fn solve(matrix: &Vec<Vec<char>>) -> usize {
    let mut st: HashSet<String> = HashSet::new();
    let n: usize = matrix.len();
    let len: usize = (n << 1) - 1;
    let mid: usize = len >> 1;
    let mut q: Vec<State> = Vec::new();
    q.push(State { x: 0, y: 0, current: matrix[0][0].to_string() });
    while !q.is_empty() {
        let top: State = q.pop().unwrap();
        let x: usize = top.x;
        let y: usize = top.y;
        let current: String = top.current.clone();
        if x == n - 1 && y == n - 1 {
            st.insert(current.clone());
        }
        for i in 0..2 {
            let nx: usize = x + DX[i];
            let ny: usize = y + DY[i];
            if is_valid(nx, ny, n) {
                let mut temp: String = current.clone();
                temp.push(matrix[nx][ny]);
                let sz: usize = temp.len();
                if sz > mid + 1 && temp.chars().nth(len - sz).unwrap() != temp.chars().last().unwrap() {
                    continue;
                }
                q.push(State { x: nx, y: ny, current: temp });
            }
        }
    }
    st.len()
}

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines: Lines<StdinLock> = stdin.lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut matrix: Vec<Vec<char>> = Vec::new();
    for _ in 0..n {
        let row: Vec<char> = lines.next().unwrap().unwrap().chars().collect();
        matrix.push(row);
    }
    println!("{}", solve(&matrix));
}
