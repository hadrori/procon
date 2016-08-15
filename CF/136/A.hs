main = interact $ unwords . map show . solve . map read . words . head . tail . lines

solve s = solve' s 1 (length s)

solve' s p n
  | p > n = []
  | otherwise = (calc s p 1):(solve' s (p+1) n)
                
calc (c:cs) p a
  | c == p = a
  | otherwise = calc cs p (a+1)
  
