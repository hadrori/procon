import Data.List
main = getLine >>= putStrLn . solve . words
solve s = show $ 4 - (length $ nub s)

