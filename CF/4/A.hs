import Control.Applicative

solve a
  | a < 3 || odd a = False
  | otherwise = True

main = do
  w <- readLn
  putStrLn $ case solve w of
    True -> "YES"
    False -> "NO"
