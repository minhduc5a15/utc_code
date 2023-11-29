use std::io::{self, BufRead};

fn main() {
    let stdin: io::Stdin = io::stdin();
    let mut input: io::StdinLock<'_> = stdin.lock();
    let mut input_line: String = String::new();
    input.read_line(&mut input_line).unwrap();
    let n: usize = input_line.trim().parse().unwrap();
    let mut arr: Vec<i64> = Vec::with_capacity(n);
    input_line.clear();
    input.read_line(&mut input_line).unwrap();
    for num in input_line.split_whitespace() {
        let val: i64 = num.trim().parse().unwrap();
        arr.push(val);
    }
    arr.sort();
    let mut s: i64 = 0;
    for i in 0..n {
        s += arr[i] * i as i64 - arr[i] * ((n - i) as i64 - 1);
    }
    println!("{}", s);
}
