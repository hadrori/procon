main = interact $ solve . map read . lines

solve (k:l:m:n:d:xs) = (show $ solve' k l m n d 1) ++ "\n"
solve' k l m n d c
  | c > d = 0
  | mod c k == 0 || mod c l == 0 ||
    mod c m == 0 || mod c n == 0 = 1 + solve' k l m n d (c+1)
  | otherwise = solve' k l m n d (c+1)
