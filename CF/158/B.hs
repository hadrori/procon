import Control.Applicative

main = do
  _ <- getLine
  s <- (map read . words) <$> getLine
  print $ solve s

--solve xs = (cnt 4) + (cnt 3) + div (3 + maximum [(cnt 1)-(cnt 3), 0] + 2 * (cnt 2)) 4
--  where cnt a = length $ filter (== a) xs

solve xs = (cnt!!3) + (cnt!!2) + div (3 + maximum [(cnt!!0)-(cnt!!2), 0] + 2 * (cnt!!1)) 4
  where cnt = [length $ filter (== a) xs | a <- [1..4]]

