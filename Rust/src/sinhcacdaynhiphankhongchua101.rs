fn solve(s: &str, n: i32) {
    let sz: usize = s.len();
    if sz == n as usize {
        return println!("{}", s);
    }
    solve(s + '0', n);
    if sz < 2 || (&s[sz - 2..sz] != "10") {
        solve(s + '1', n);
    }
}

fn main() {
    let mut n: String = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();
    solve("0", n);
    solve("1", n);
}
