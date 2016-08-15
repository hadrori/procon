w=gets.to_i
d=gets.to_i
while d > 1
  w -= w/(d*d)
  d -= 1
end
p w/(d*d)
