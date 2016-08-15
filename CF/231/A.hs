import Control.Applicative

main = interact $ show . length . filter (>1) . map (length . filter (=='1')) . tail . lines

  
