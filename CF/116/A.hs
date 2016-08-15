import Control.Monad
import Control.Applicative

main = do
  n <- readLn
  s <- replicateM n $ map read . words <$> getLine
  print $ maximum (solve s 0)

solve [] _ = []
solve (x:xs) num = num: solve xs (num+(last x)-(head x))


