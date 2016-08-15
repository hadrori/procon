import Control.Applicative

main = do
  [n, m, a] <- (map read . words) <$> getLine
  print $ (div (n+a-1) a) * (div (m+a-1) a)
