use std::io::{stdin, BufRead};

const MOD: u128 = 1000000000000007;
const SIZE: usize = 3;

type Matrix = [[u128; SIZE]; SIZE];

fn multiply(matrix_a: &Matrix, matrix_b: &Matrix) -> Matrix {
    let mut result = [[0u128; SIZE]; SIZE];
    for i in 0..SIZE {
        for j in 0..SIZE {
            for k in 0..SIZE {
                result[i][j] = (result[i][j] + matrix_a[i][k] * matrix_b[k][j]) % MOD;
            }
        }
    }
    result
}

fn power(mut base: Matrix, mut exponent: u128) -> Matrix {
    let mut result = [[1u128, 0, 0], [0, 1, 0], [0, 0, 1]];
    while exponent > 0 {
        if exponent & 1 == 1 {
            result = multiply(&result, &base);
        }
        base = multiply(&base, &base);
        exponent >>= 1;
    }
    result
}

fn solve(n: u128) -> u128 {
    let f: Matrix = [[1, 1, 1], [1, 0, 0], [0, 1, 0]];
    let v: [u128; 3] = [1, 1, 0];
    let f_n = power(f, n);
    let mut res = 0;
    for i in 0..SIZE {
        res = (res + (f_n[0][i] * v[i]) % MOD) % MOD;
    }
    res - 1
}

fn main() {
    let mut lines = stdin().lock().lines();
    let line = lines.next().unwrap().unwrap();
    let t: usize = line.parse().unwrap();
    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let n: u128 = line.parse().unwrap();
        println!("{}", solve(n));
    }
}
