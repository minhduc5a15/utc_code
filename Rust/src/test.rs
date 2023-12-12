use std::io;

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).expect("");
    let n: i32 = input.trim().parse().expect("");
    input.clear();
    io::stdin().read_line(&mut input).expect("");
    let mut arr: Vec<i32> = input.split_whitespace().map(|s| s.parse().expect("")).collect();
    arr.sort(); // sort the array;
    println!("{:?}", arr); //print the sorted array;
}