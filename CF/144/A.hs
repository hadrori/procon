import Control.Applicative
main = do
  n <- readLn
  a <- map read . words <$> getLine
  print $ solve a (0, 0) (101, 0) 0 n

solve [] (_, a) (_, b) _ n = a+n-b-1-(if a > b then 1 else 0)
solve (a:as) (ma, maxp) (mi, minp) p n =
  solve as (if ma < a then (a, p) else (ma, maxp)) (if mi >= a then (a, p) else (mi, minp)) (p+1) n
  


