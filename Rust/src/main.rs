fn inverse_matrix(matrix: &mut Vec<Vec<f64>>, n: usize) -> Result<Vec<Vec<f64>>, &'static str> {
    let mut inv_matrix: Vec<Vec<f64>> = vec![vec![0.0; n]; n];
    for i in 0..n {
        inv_matrix[i][i] = 1.0;
    }
    for i in 0..n {
        if matrix[i][i] == 0.0 {
            return Err("khong co ma tran nghich dao");
        }
        for j in 0..n {
            if i != j {
                let ratio: f64 = matrix[j][i] / matrix[i][i];
                for k in 0..n {
                    matrix[j][k] -= ratio * matrix[i][k];
                    inv_matrix[j][k] -= ratio * inv_matrix[i][k];
                }
            }
        }
        let pivot: f64 = matrix[i][i];
        for k in 0..n {
            matrix[i][k] /= pivot;
            inv_matrix[i][k] /= pivot;
        }
    }
    
    Ok(inv_matrix)
}

fn main() {
    let mut matrix: Vec<Vec<f64>> = Vec::new();
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("");
    let n: usize = input.trim().parse().expect("");
    for _ in 0..n {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("");
        let rows: Vec<f64> = input
            .split_whitespace()
            .map(|s: &str| s.trim().parse().expect(""))
            .collect();
        matrix.push(rows);
    }
    match inverse_matrix(&mut matrix, n) {
        Ok(result) => {
            for rows in result {
                println!("{}", rows.iter().map(|&x| format!("{:.6}", x)).collect::<Vec<_>>().join(" "));
            }
        }
        Err(err) => println!("{}", err),
    }
}
