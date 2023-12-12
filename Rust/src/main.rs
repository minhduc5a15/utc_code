use std::collections::{HashSet, BTreeMap};

fn print(x: i32, map: &BTreeMap<i32, i32>) {
    println!("{} {}", x, map.get(&x).unwrap_or(&0));
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let arr: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let mut s = HashSet::new();
    let mut map = BTreeMap::new();

    s.insert(arr[0]);
    for &item in &arr {
        if let Some(&it) = s.iter().filter(|&&x| x >= item).next() {
            if it == item {
                continue;
            }
            if s.get(&(item - 1)).is_none() {
                map.insert(item, *map.get(&(item - 1)).unwrap_or(&0));
            } else if s.get(&(item - 1)).is_some() && s.get(&(item - 1)).unwrap() == s.iter().next().unwrap() {
                map.insert(item, *map.get(&item).unwrap_or(&0));
            } else {
                map.insert(item, *map.get(&item).unwrap_or(&0));
                map.insert(item, map[&item].max(*map.get(&(item - 1)).unwrap_or(&0)));
            }
            *map.entry(item).or_insert(0) += 1;
            s.insert(item);
        }
    }

    for &item in &s {
        print(item, &map);
    }
}
