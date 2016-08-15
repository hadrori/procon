k,n=gets.split.map(&:to_i)
a=k*n-gets.split.map(&:to_i).inject(:+)
a=-1 if a<0
p a
