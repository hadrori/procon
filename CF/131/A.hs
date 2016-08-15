import Data.Char

main = getLine >>= putStrLn . solve

solve [] = []
solve s
  | check $ tail s = work s
  | otherwise = s
  where 

check [] = True
check (x:xs) = ('A' <= x && x <= 'Z') && (check xs)

work [] = []
work (c:cs)
  | 'A' <= c && c <= 'Z' = chr (ord c + ord 'a' - ord 'A') : work cs
  | otherwise = chr (ord c + ord 'A' - ord 'a'): work cs
