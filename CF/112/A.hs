import Data.Char

main = interact $ solve . lines

solve l = (show $ solve' (head l) (last l)) ++ "\n"

solve' [] _ = 0
solve' (a:as) (b:bs)
  | c == d = solve' as bs
  | c < d = -1
  | otherwise = 1
  where
    toLower x
      | 'a' <= x && x <= 'z' = x
      | otherwise = chr (ord x - ord 'A' + ord 'a')
    c = toLower a
    d = toLower b


