use std::io::{self, BufRead};

fn main() {
    let stdin: io::Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let n: String = lines.next().unwrap().unwrap();
    let mut j: usize = 1;
    loop {
        let curr: i32 = n[0..j].parse().unwrap();
        let mid: String = (curr - 1).to_string();
        if n.find(&mid) == Some(j) && n.find(&(curr - 2).to_string()) == Some(j + mid.len()) {
            println!("{}", curr);
            return;
        }
        j += 1;
    }
}