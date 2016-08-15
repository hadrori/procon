import Control.Monad
import Control.Applicative

main = do
  getLine
  l <- getContents
  let x = map (map read . words) $ lines l :: [[Int]]
  print $ solve x

solve [] = 0
solve (a:xs) = (solve' a xs) + (solve xs)

solve' _ [] = 0
solve' a@[ah, aa] (([bh, ba]):xs) =
  (if ah==ba then 1 else 0) + (if aa==bh then 1 else 0) + solve' a xs



