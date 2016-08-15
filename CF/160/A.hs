import Data.List

main = interact $ solve . map read . words . head . tail . lines

solve s = (show $ solve' (reverse $ sort s) (div (sum s) 2) 0) ++ "\n"
solve' [] _ _ = 0
solve' (x:xs) p c
  | c > p = 0
  | otherwise = 1 + solve' xs p (c+x)

