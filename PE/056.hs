import Data.Char
digitalSum = sum . map digitToInt . show
main = print $ maximum ( map digitalSum [a ^ b | a <- [1..99], b <- [1..99]] )
