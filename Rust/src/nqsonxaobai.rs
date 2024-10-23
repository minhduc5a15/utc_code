use std::io;
use std::collections::VecDeque;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let numbers: Vec<i32> = input.split_whitespace().map(|num| num.parse().unwrap()).collect();
    let mut q = VecDeque::new();
    for i in 0..n {
        q.push_back(numbers[i]);
    }
    while !q.is_empty() {
        let front = q.pop_front().unwrap();
        q.push_back(front);
        print!("{} ", q.pop_front().unwrap());
    }
}
