v=gets.to_i
gets.to_i.times do
  a,b=gets.split.map(&:to_i)
  v = v==a ? b : v==b ? a : v
end
p v
