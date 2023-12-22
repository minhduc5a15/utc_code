def solve(nums) -> int:
        count = {}
        result = 0
        n = len(nums)
        for i in range(n - 2, 0, -1):
            for j in range(i + 1, n):
                num = nums[i] + nums[j]
                count[num] = count.get(num, 0) + 1
            for j in range(i - 2, -1, -1):
                num = nums[j] + nums[i - 1]
                result += count.get(num, 0)
        return result
n = input()
print(solve(list(map(int, input().split()))))
