--題意勘違い
m = 10000000000000000
pow_mod x e
    | e == 0 = 1
    | (mod e 2) == 1 = mod (x*(pow_mod x (e-1))) m
    | otherwise = pow_mod (mod (x*x) m) (div e 2)

n = div 250250 250
main = print((pow_mod 2 n) - 1)
