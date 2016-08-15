list_digits 0 = []
list_digits n = mod n 10: list_digits (div n 10)

numerize a = foldr (\x y -> x + y * 10) 0 a
is_palindromic n = n == numerize(reverse(list_digits n))
num_list = [100..999]
a = filter is_palindromic [m * n | m <- num_list, n <- num_list]
main = print (maximum a)
