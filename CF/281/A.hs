import Data.Char

main = getLine >>= putStrLn . solve

solve s@(c:cs)
  | 'a' <= c && c <= 'z' = chr(ord c - 32):cs
  | otherwise = s                    

