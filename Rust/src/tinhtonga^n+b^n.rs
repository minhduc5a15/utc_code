const MOD: i64 = 1_000_000_007;
const SIZE: usize = 2;

type Matrix = Vec<Vec<i64>>;

fn multiply(a: &Matrix, b: &Matrix) -> Matrix {
    let mut result: Vec<Vec<i64>> = vec![vec![0; SIZE]; SIZE];
    for i in 0..SIZE {
        for j in 0..SIZE {
            for k in 0..SIZE {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

fn pow(mat: &Matrix, mut power: i32) -> Matrix {
    let mut result: Vec<Vec<i64>> = mat.clone();
    let mut temp: Vec<Vec<i64>> = mat.clone();
    power -= 1;
    while power != 0 {
        if power & 1 != 0 {
            result = multiply(&result, &temp);
        }
        temp = multiply(&temp, &temp);
        power >>= 1;
    }
    result
}

fn main() {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("");
    let mut nums = input.trim().split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let p: i64 = nums.next().unwrap();
    let s: i64 = nums.next().unwrap();
    let f: Vec<Vec<i64>> = vec![
        vec![s * s * s - 3 * p * s, s * s - 2 * p],
        vec![s * s - 2 * p, s],
    ];
    let a: Vec<Vec<i64>> = vec![
        vec![s, 1],
        vec![-p, 0],
    ];
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("");
    let n: i32 = input.trim().parse().unwrap();
    if n <= 3 {
        println!("{}", f[0][0]);
    } else {
        let pow_result: Matrix = pow(&a, n - 3);
        let result: Matrix = multiply(&f, &pow_result);
        println!("{}", (result[0][0] + MOD) % MOD);
    }
}

