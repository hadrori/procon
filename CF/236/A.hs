import Data.List
main = getLine >>= putStrLn . solve . nub
solve s
  | odd $ length s = "IGNORE HIM!"
  | otherwise = "CHAT WITH HER!"
  
