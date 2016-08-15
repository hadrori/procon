import Math.NumberTheory.Powers

m = 1000000000

calc n = (if (mod a 16 == 0) && (isSquare a) then 3*n + 1 else 0) +
         (if (mod b 16 == 0) && (isSquare b) then 3*n - 1 else 0)
    where 
      a = (n^2 - 1) * (3*n^2 + 4*n + 1)
      b = (n^2 - 1) * (3*n^2 - 4*n + 1)
main = print(sum $ map calc [1,3 .. (div m 3)])
