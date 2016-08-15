main = getLine >>= putStrLn . solve . map read . words
solve (a:b:_) = show $ a + (solve' a b)
solve' a b
  | a >= b = c + (solve' (a-c*b+c) b)
  | otherwise = 0
  where c = div a b

