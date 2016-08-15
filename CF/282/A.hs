import Control.Monad

main = do
  n <- readLn
  s <- replicateM n getLine
  print $ calc s '+'  - calc s '-'

calc a c = length $ filter (\x -> (length x) > 0) $ map (filter (==c)) a
