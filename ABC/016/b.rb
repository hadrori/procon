a,b,c=gets.split.map(&:to_i)
f,g=a+b==c,a-b==c
puts (f&&g)? '?': f ? '+': g ? '-': '!'
