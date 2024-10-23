class Solution:
    def __init__(self):
        self.F = ["0", "1"] + [""] * 99
        self.f = [1, 1] + [0] * 99

    def pre_compute_fib(self, m):
        i = 1
        while i < 3 or len(self.F[i - 3]) < m:
            self.F[i + 1] = self.F[i] + self.F[i - 1]
            i += 1

    def pre_compute(self, m):
        for i in range(1, m):
            self.f[i + 1] = self.f[i] + self.f[i - 1]

    def occurrences(self, n, p):
        if p == "0":
            return self.f[n - 2] if n >= 2 else (1 if n == 0 else 0)
        if p == "1":
            return self.f[n - 1] if n >= 2 else (0 if n == 0 else 1)

        m = 3
        while self.f[m - 3] <= len(p):
            m += 1
        if m > n:
            m = n

        a = b = 0
        o = [0, 0]

        occurrences = KMP.search(self.F[m], p, self.f[m - 1])
        for found in occurrences:
            if found < self.f[m - 2]:
                if found + len(p) - 1 < self.f[m - 2]:
                    b += 1
                else:
                    o[0] += 1
            elif found < self.f[m - 1]:
                if found + len(p) - 1 < self.f[m - 1]:
                    a += 1
                else:
                    o[1] += 1

        for i in range(n - m + 2):
            old_b = b
            b = b + a + o[i % 2]
            a = old_b

        return b

class KMP:
    @staticmethod
    def border_array(s):
        x = list(s)
        n = len(x)
        beta = [0] * n
        b = 0
        for i in range(1, n):
            while b > 0 and x[i] != x[b]:
                b = beta[b - 1]
            beta[i] = b = b + 1 if x[i] == x[b] else 0
        return beta

    @staticmethod
    def search(xx, pp, max_index):
        x = list(xx)
        p = list(pp)
        beta = KMP.border_array(pp)
        i = m = 0
        results = []
        while m + i < len(x):
            if m > max_index:
                break
            if x[m + i] == p[i]:
                if i == len(p) - 1:
                    results.append(m)
                else:
                    i += 1
                    continue
            if i > 0:
                m = m + i - beta[i - 1]
                i = beta[i - 1]
            else:
                m = m + 1
                i = 0
        return results

if __name__ == "__main__":
    problem = Solution()
    problem.pre_compute_fib(100000)
    problem.pre_compute(100)

    c = 1
    while True:
        try:
            n = int(input())
            p = input()
            print(f"Case {c}: {problem.occurrences(n, p)}")
            c += 1
        except EOFError:
            break