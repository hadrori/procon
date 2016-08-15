ans = sum [x | x <- takeWhile (< 4000000) fib, even x] 
      where fib = 1 : 1 : zipWith (+) fib (tail fib)
main = print(ans)