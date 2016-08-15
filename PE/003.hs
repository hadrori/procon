--ans :: Integer
prime = 2 : 3 : [[6 * x - 1, 6 * x + 1] | x <- [1 .. ]]
main = print(factors 600851475143)