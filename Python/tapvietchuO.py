print(*["thuong" if (s := input()) == 'o' else "hoa" if s == 'O' else "khong" if s == '0' else "" for _ in range(10)], sep='\n')
