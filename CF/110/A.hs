main = getLine >>= putStrLn . solve
solve s = if islucky $ show $ length $ filter (\x -> x=='4' || x=='7') s then "YES" else "NO"
  where islucky c = (length . filter (\x -> x/='4' && x/='7')) c == 0
