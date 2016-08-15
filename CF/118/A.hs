import Control.Applicative
import Data.Char

vow = "aiueoy"

main = getLine >>= putStrLn . solve

solve [] = []
solve (x:xs)
  | elem y vow = solve xs
  | otherwise = ['.', y] ++ solve xs
  where y = cap x

cap c
  | 'A' <= c && c <= 'Z' = chr (ord c - ord 'A' + ord 'a')
  | otherwise = c
               
