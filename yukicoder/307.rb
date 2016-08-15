n,m=gets.split.map(&:to_i)
c=gets.split.map(&:to_i).sort
sum = 0
n.times do |i|
  sum += c[i]
  if sum >= m
    p i+1 if sum == m
    p i if sum > m
    break
  end
end
