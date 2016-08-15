import Data.List

main = getLine >>= putStrLn.solve.read
solve n = solve' (n+1)
solve' n = if (length.nub.show) n == (length.show) n then show n else solve' (n+1)
