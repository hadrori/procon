n=gets.to_i
a=gets.split.map(&:to_i)
sum = 0
(n-2).times do |i|
  b = a[i,3].sort
  next if b[0] == b[1] or b[1] == b[2]
  sum += 1 if a[i] == b[1] or a[i+2] == b[1]
end
p sum
