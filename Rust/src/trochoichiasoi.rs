use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut lines = input.lines();
    let t: i32 = lines.next().unwrap().parse().unwrap();

    for (i, line) in lines.enumerate() {
        let n: i32 = line.parse().unwrap();
        println!("Test Case #{}: {}", i + 1, if n % 2 == 1 { "Kratos" } else { "Atreus" });
    }
}