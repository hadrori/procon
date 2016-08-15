import Control.Applicative

main = do
  [n, k] <- (map read . words) <$> getLine
  a <- (map read . words) <$> getLine
  print $ length (takeWhile (\x -> x > 0 && x >= a!!(k-1)) a)
