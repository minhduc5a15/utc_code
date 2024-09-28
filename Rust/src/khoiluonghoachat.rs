use std::io;

fn solve(s: &str) -> i32 {
    let mass: std::collections::HashMap<char, i32> = [('H', 1), ('C', 12), ('O', 16)].iter().cloned().collect();
    let mut stack: Vec<i32> = Vec::new();
    for char in s.chars() {
        if char.is_alphabetic() {
            stack.push(*mass.get(&char).unwrap());
        } else if char.is_numeric() {
            let temp = stack.pop().unwrap() * char.to_digit(10).unwrap() as i32;
            stack.push(temp);
        } else if char == '(' {
            stack.push(-1);
        } else if char == ')' {
            let mut temp: i32 = 0;
            while let Some(top) = stack.pop() {
                if top == -1 {
                    break;
                }
                temp += top;
            }
            stack.push(temp);
        }
    }

    stack.iter().sum()
}

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let t: i32 = input.trim().parse().expect("Invalid input");

    for _ in 0..t {
        let mut input: String = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        println!("{}", solve(input.trim()));
    }
}