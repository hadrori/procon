n=gets.to_i
a=n.times.map{gets.to_i}
p a.inject(0.0){|x,v|b=a.count{|w|v%w==0}-1;x+=(b+2)/2/(b+1.0)}
