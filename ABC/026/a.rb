n=gets.to_i
p (0..n).to_a.map{|v|v*(n-v)}.max
