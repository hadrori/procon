import Control.Applicative

main = do
  [n, m] <- (map read . words) <$> getLine
  print $ div (n*m) 2


