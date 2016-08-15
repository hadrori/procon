main = getLine >>= putStrLn . solve

hq = "HQ9"
solve [] = "NO"
solve (c:cs)
  | elem c hq = "YES"
  | otherwise = solve cs
