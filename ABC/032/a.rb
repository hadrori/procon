a=3.times.map{gets.to_i}
a[2] += 1 while (a[2]%a[0] != 0 or a[2]%a[1] != 0)
p a[2]
