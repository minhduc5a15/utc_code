// AC 37/50 :<

use std::io;

const MAXN: usize = 500;
const MOD: i128 = 2 * 10i128.pow(18) + 1;

fn mod_pow(mut base: i128, mut exp: i128, modulus: i128) -> i128 {
    if modulus == 1 { return 0 }
    let mut result: i128 = 1;
    base = base % modulus;
    while exp > 0 {
        if exp % 2 == 1 {
            result = result * base % modulus;
        }
        exp = exp >> 1;
        base = base * base % modulus
    }
    result
}

fn sieve() -> Vec<usize> {
    let mut primes = vec![true; MAXN];
    let mut p = 2;
    while p * p <= MAXN {
        if primes[p] {
            let mut i = p * p;
            while i < MAXN {
                primes[i] = false;
                i += p;
            }
        }
        p += 1;
    }
    primes[0] = false;
    primes[1] = false;
    let mut prime_numbers = vec![2];
    prime_numbers.extend((3..MAXN).step_by(2).filter(|&i| primes[i]));
    prime_numbers
}

fn divisors(mut n: i128) -> Vec<i128> {
    let mut result = vec![];
    while n % 2 == 0 {
        result.push(2);
        n >>= 1;
    }
    let mut i = 3;
    while i * i <= n {
        while n % i == 0 {
            result.push(i);
            n /= i;
        }
        i += 2;
    }
    if n != 1 {
        result.push(n);
    }
    result.sort_unstable_by(|a, b| b.cmp(a));
    result
}

fn get(x: i128, mut y: i128) -> i128 {
    if y < x { return 0; }
    let mut count = 0;
    while y > 0 {
        count += 1;
        y /= x;
    }
    count - 1
}

fn solve(n: i128, mut prime_numbers: Vec<usize>) -> i128 {
    let mut res: i128 = 1;
    let mut nums = divisors(n);
    let sz = nums.len();
    if sz == 1 { return mod_pow(2, nums[0] - 1, MOD); }
    prime_numbers = prime_numbers[0..sz].to_vec();

    while !nums.is_empty() {
        while nums[0] * (nums.last().unwrap() - 1) < get(prime_numbers[0] as i128, *prime_numbers.last().unwrap() as i128) {
            *nums.first_mut().unwrap() *= *nums.last().unwrap();
            nums.pop();
            prime_numbers.pop();
        }
        res = (res * mod_pow(prime_numbers[0] as i128, *nums.first().unwrap() - 1, MOD)) % MOD;
        nums.remove(0);
        prime_numbers.remove(0);
    }
    res % MOD
}

fn main() {
    let prime_numbers = sieve();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i128 = input.trim().parse().unwrap();
    println!("{}", solve(n, prime_numbers));
}