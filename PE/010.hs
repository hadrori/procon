n = 2000000
is_prime m = all (\p -> mod m p /= 0) (takeWhile (\p -> p * p <= m) primes)
primes = 2:[m | m < [3,5..n], is_prime m]
main = print(sum primes)
