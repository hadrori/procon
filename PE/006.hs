n = 100
s = sum [1..100]
t = sum [n^2 | n <- [1..n]]
main = print(s^2 - t)

