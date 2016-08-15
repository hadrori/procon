n = 1000
isPythagorean (a:b:c:[]) = a * a + b * b == c * c
divide n m l | n < l = []
             | m == 1 = [[n]]
divide n m l = foldr (++) [] [f p n m | p <- [l..(div n m)]]
f p n m = map (\x -> [p] ++ x) (divide (n - p) (m - 1) (p + 1))

main = print(head (map product (filter isPythagorean (divide n 3 1))))
