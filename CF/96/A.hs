main = getLine >>= putStrLn . solve

solve s = solve' s '2' 0
solve' [] _ cnt = if cnt > 6 then "YES" else "NO"
solve' (p:ps) prev cnt
  | cnt > 6 = "YES"
  | prev == p = solve' ps p (cnt+1)
  | otherwise = solve' ps p 1
