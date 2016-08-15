a,b,n=gets.split.map(&:to_i)
p n%3==0 ? a : n%3==1 ? b : a^b
