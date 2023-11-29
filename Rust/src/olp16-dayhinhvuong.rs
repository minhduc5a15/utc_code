use std::io;
const MOD: u128 = 1000000007;
fn power(mut base: u128, mut exponent: u128) -> u128 {
    base %= MOD;
    let mut result: u128 = 1;
    while exponent > 0 {
        if exponent & 1 != 0 {
            result = (result * base) % MOD;
        }
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return result % MOD;
}
fn solve(u1: u128, n: u128) -> u128 {
    let b: u128 = ((power(4, n + 1) - 1) * power(3, MOD - 2)) % MOD;
    return (u1 * b) % MOD;
}
fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).expect("");
    let mut iter: std::str::SplitWhitespace<'_> = input.split_whitespace();
    let a: u128 = iter.next().expect("").parse().expect("");
    let b: u128 = iter.next().expect("").parse().expect("");
    println!("{}", solve(b * b, a));
}
