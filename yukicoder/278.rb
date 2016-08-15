i=0
j=0
s="NESW"
di = [1,0,-1,0]
dj = [0,1,0,-1]
gets.strip.chars do |c|
  i += di[s.index(c)]
  j += dj[s.index(c)]
end
p Math.sqrt(i*i+j*j)
