n=gets.to_i
a=0
b=0
n.times do
  t,s=gets.split
  c=t.to_i
  d=s.length
  a += [c*12/1000,d].min
  b += [d-c*12/1000,0].max
end
puts a.to_s+' '+b.to_s
