n,m=gets.split.map(&:to_i)
p gets.split.map(&:to_f).sort.drop(n-m).inject(0){|a,x|a=(a+x)/2}
