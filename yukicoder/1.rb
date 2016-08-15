n=gets.to_i
m=n*3
f=[0]*11
x=0
n.times do
  a,b,c=gets.split.map(&:to_i)
  if f[a] > 0
    x+=1
    m-=2
    f[a] = 0
  else f[a] = 1 end
  if f[b] > 0
    x+=1
    m-=2
    f[b] = 0
  else f[b] = 1 end
  if f[c] > 0
    x+=1
    m-=2
    f[c] = 0
  else f[c] = 1 end
end
p x+m/4
