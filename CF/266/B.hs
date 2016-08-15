import Control.Applicative

main = do
  [_, t] <- map read . words <$> getLine
  s <- getLine
  putStrLn $ solve t s

solve 0 s = s
solve t s = solve (t-1) (work s)

work [] = []
work (a:[]) = a:[]
work (a:b:ls)
  | a == 'B' && b == 'G' = b:a:(work ls)
  | otherwise = a:(work (b:ls))
                
