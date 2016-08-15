gets
x=gets.split.map(&:to_i).sort.uniq
n=x.length
f = 0
if n > 1
  f=x[1]-x[0]
  (n-1).times do |i|
    f=[f,x[i+1]-x[i]].min
  end
end
p f
