gets
p gets.split.map(&:to_i).map{|v|
  w = v
  v -= 1 while v%2==0 or v%3==2
  w-v
}.inject(:+)
