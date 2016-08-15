c=gets.to_i
a,b=gets.split.map(&:to_f)
r=(b-a)/2
p r*r*Math::PI*(a+b)*Math::PI*c
