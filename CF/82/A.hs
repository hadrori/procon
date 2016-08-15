main = do
  n <- readLn
  putStrLn $ solve n 5 0

solve n sum i
  | sum < n = solve n (sum+5*2^(i+1)) (i+1)
  | otherwise = let s = sum-5*2^i;
                    m = div (n-s-1) (2^i);
                in ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"] !! m
