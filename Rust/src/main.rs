use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|x| x.unwrap());

    let input_line = lines.next().unwrap();
    let mut input_iter = input_line.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = input_iter.next().unwrap();
    let h = input_iter.next().unwrap();

    let mut top = vec![0; (h + 1) as usize];
    let mut bottom = vec![0; (h + 1) as usize];

    for (i, line) in lines.take(n as usize).enumerate() {
        let x: i32 = line.parse().unwrap();
        if i % 2 == 1 {
            top[x as usize] += 1;
        } else {
            bottom[x as usize] += 1;
        }
    }

    let mut res = (i32::MAX, 0);

    for i in (0..h).rev() {
        top[i as usize] += top[(i + 1) as usize];
        bottom[i as usize] += bottom[(i + 1) as usize];
    }

    for i in 1..=h {
        if bottom[i as usize] + top[(h - i + 1) as usize] == res.0 {
            res.1 += 1;
        }
        if bottom[i as usize] + top[(h - i + 1) as usize] < res.0 {
            res.1 = 1;
            res.0 = bottom[i as usize] + top[(h - i + 1) as usize];
        }
    }

    println!("{} {}", res.0, res.1);
}
