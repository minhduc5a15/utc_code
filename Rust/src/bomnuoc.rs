use std::cmp::Ordering;
use std::io::{self, BufRead, Write};

#[derive(Debug, Clone)]
struct Container {
    b: i32,
    h: f64,
    w: f64,
    d: f64,
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_lock = stdin.lock();
    let stdout = io::stdout();
    let mut stdout_lock = stdout.lock();
    let mut input = String::new();
    stdin_lock.read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut v: f64 = iter.next().unwrap().parse().unwrap();
    let mut arr: Vec<Container> = Vec::with_capacity(n);
    for _ in 0..n {
        input.clear();
        stdin_lock.read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let h: f64 = iter.next().unwrap().parse().unwrap();
        let w: f64 = iter.next().unwrap().parse().unwrap();
        let d: f64 = iter.next().unwrap().parse().unwrap();
        arr.push(Container { b, h, w, d });
    }

    arr.sort_by(|a, b| a.b.cmp(&b.b));
    let mut events: Vec<(i32, f64)> = Vec::with_capacity(2 * n);
    for tank in &arr {
        events.push((tank.b, tank.w * tank.d));
        events.push((tank.b + tank.h as i32, -(tank.w * tank.d)));
    }
    events.sort_by(|a, b| {
        if a.0 == b.0 {
            a.1.partial_cmp(&b.1).unwrap_or(Ordering::Equal)
        } else {
            a.0.cmp(&b.0)
        }
    });
    let mut current_v = 0.0;
    let mut current_h = 0;
    for i in 0..n {
        let next_height = events[i].0;
        if i > 0 && current_v * (next_height - current_h) as f64 >= v {
            let res = v / current_v;
            write!(stdout_lock, "{:.2}", current_h as f64 + res).unwrap();
            return;
        }
        if i > 0 {
            v -= (next_height - current_h) as f64 * current_v;
        }
        current_h = next_height;
        current_v += events[i].1;
    }

    if current_v > 0.0 {
        let res = current_h as f64 + v / current_v;
        write!(stdout_lock, "{:.2}", res).unwrap();
    }
}
