use std::collections::HashMap;

fn calc(a: i32, b: i32, op: char) -> i32 {
    match op {
        '+' => a + b,
        '-' => a - b,
        '*' => a * b,
        '/' => a / b,
        _ => panic!("Invalid operator"),
    }
}

fn main() {
    let mut precedence: HashMap<char, i32> = HashMap::new();
    precedence.insert('+', 1);
    precedence.insert('-', 1);
    precedence.insert('*', 2);
    precedence.insert('/', 2);
    precedence.insert('(', 0);

    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("Failed to read input");
    let s = s.trim().to_string();

    let mut post_fix = String::new();
    let mut operators: Vec<char> = Vec::new();

    for c in s.chars() {
        if c.is_digit(10) {
            post_fix.push(c);
        } else if c == '(' {
            operators.push(c);
        } else if precedence.contains_key(&c) {
            while !operators.is_empty() && *precedence.get(operators.last().unwrap()).unwrap() >= precedence[&c] {
                post_fix.push(*operators.last().unwrap());
                operators.pop();
            }
            operators.push(c);
        } else if c == ')' {
            while *operators.last().unwrap() != '(' {
                post_fix.push(*operators.last().unwrap());
                operators.pop();
            }
            operators.pop();
        }
    }

    while let Some(op) = operators.pop() {
        post_fix.push(op);
    }
    println!("{}", post_fix);
    let mut operands: Vec<i32> = Vec::new();

    for c in post_fix.chars() {
        if c.is_digit(10) {
            operands.push(c.to_digit(10).unwrap() as i32);
        } else {
            let k = operands.pop().unwrap();
            let prev = operands.pop().unwrap();
            operands.push(calc(prev, k, c));
        }
    }

    println!("{}", operands.pop().unwrap());
}
