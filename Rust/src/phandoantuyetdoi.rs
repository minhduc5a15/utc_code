use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("");
    let n: usize = input.trim().parse().expect("");
    let mut arr: Vec<i64> = vec![0; n + 1];
    let mut x_input = String::new();
    io::stdin().read_line(&mut x_input).expect("");
    let x_values: Vec<i64> = x_input
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();
    for i in 1..=n {
        arr[i] = arr[i - 1] + x_values[i - 1];
    }
    arr.sort();
    let mut res: i64 = std::i64::MAX;
    for i in 1..=n {
        res = res.min((arr[i] - arr[i - 1]).abs());
    }
    print!("{} {}", arr.last().unwrap() - arr.first().unwrap(), res);
}