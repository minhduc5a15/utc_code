use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut lines = input.lines();
    let n: usize = lines.next().unwrap().parse().unwrap();

    let mut arr = Vec::<String>::with_capacity(n);
    for line in lines.take(n) {
        arr.push(line.to_owned());
    }

    let l = arr[0].len();
    let mut index = 0;
    let mut res = String::new();

    for i in 0..l {
        let mut min_c = 'z';
        for j in index..n {
            if arr[j].as_bytes()[i] < min_c as u8 {
                min_c = arr[j].as_bytes()[i] as char;
                index = j;
            }
        }
        res.push(min_c);
    }

    println!("{}", res);
}
