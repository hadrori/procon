import Control.Applicative
import Control.Monad

main = do
  n <- readLn
  ws <- replicateM n getLine
  mapM_ (putStrLn . solve) ws
  
solve w
  | length w <= 10 = w
  | otherwise = (head w) : (show $ (length w) - 2) ++ [last w]
                     
  
