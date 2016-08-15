sum = 0
gets.to_i.times do
  c,d=gets.split.map(&:to_i)
  sum = (sum+(c+1)/2*d)%1000000007
end
p sum
