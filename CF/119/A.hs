main = getLine >>= putStrLn . solve . map read . words

solve (a:b:n:xs) = show $ solve' a b n 0
solve' _ _ 0 p = mod (p+1) 2
solve' a b n p = solve' b a (n-(gcd a n)) (mod (p+1) 2)

