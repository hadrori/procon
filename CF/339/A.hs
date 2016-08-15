import Data.List
main = getLine >>= putStrLn . intersperse '+' . sort . filter (/='+')
