def find_even_length_palindrome(N):
    count = 0
    num = 1
    while True:
        str_num = str(num)
        palindrome = int(str_num + str_num[::-1])
        count += 1
        if count == N:
            return palindrome
        num += 1
print(find_even_length_palindrome(int(input())))
