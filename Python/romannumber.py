def convert_to_roman(n):
    arr_1 = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
    arr_2 = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    arr_3 = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    
    t1 = n % 10
    n //= 10
    t2 = n % 10
    n //= 10
    t3 = n % 10
    
    return arr_1[t3] + arr_2[t2] + arr_3[t1]

n = int(input())
print(convert_to_roman(n))
