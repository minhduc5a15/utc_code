def segmented_sieve(L, R):
    limit = int(R**0.5) + 1
    primes = [True]*limit
    primes[0] = primes[1] = False

    for ind, val in enumerate(primes):
        if ind > 1 and val is True:
            primes[ind*ind: limit: ind] = [False]*len(primes[ind*ind: limit: ind])

    low_primes = [ind for ind, val in enumerate(primes) if val is True]

    primes = [True]*(R-L+1)

    for prime in low_primes:
        start = max(prime*prime, (L//prime)*prime)
        if start < L:
            start += prime
        primes[start-L: R-L+1: prime] = [False]*len(primes[start-L: R-L+1: prime])

    if L == 1:
        primes[0] = False

    return primes

T = int(input().strip())
tests = [list(map(int, input().strip().split())) for _ in range(T)]

for L, R in tests:
    primes = segmented_sieve(L, R)
    count = sum(primes)
    print(count)
