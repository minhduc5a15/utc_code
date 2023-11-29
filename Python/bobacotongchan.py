def count_triplets(arr, n):
    even_count = len([x for x in arr if x % 2 == 0])
    odd_count = n - even_count
    even_triplets = even_count * (even_count - 1) * (even_count - 2) // 6
    odd_even_triplets = odd_count * (odd_count - 1) // 2 * even_count
    return even_triplets + odd_even_triplets
n = int(input())
print(count_triplets(list(map(int, input().split())), n))