a,b = gets.split.map(&:to_i)
for i in a..b
  p i if i%3 == 0 or i.to_s.scan('3').length > 0
end
