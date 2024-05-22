a, b = map(int, input().split())
c, d = map(int, input().split())
m_1, m_2 = max(a, b), max(c, d)
print("YES" if (a + c == b or a + d == b or b + c == a or b + d == a) and (m_1 == m_2) else "NO")