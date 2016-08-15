main = interact $ solve . head . tail . lines

solve s = (show $ solve' s ' ') ++ "\n"

solve' [] _ = 0
solve' (x:xs) c
  | x == c = 1 + solve' xs c
  | otherwise = solve' xs x
