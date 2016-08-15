s=gets.strip
c=0
8.times{c+=gets.count('wb')}
if s=="oda"
  puts c%2>0 ? "yukiko" : "oda"
else
  puts c%2>0 ? "oda" : "yukiko"
end
