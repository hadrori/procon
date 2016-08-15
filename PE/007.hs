n = 10001
is_prime m = all (\p -> mod m p /= 0) (takeWhile (\p -> m >= p * p) primes)
primes = 2:[m | m <- [3,5..], is_prime m]
main = print(last (take n primes))
