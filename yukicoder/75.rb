x=gets.to_i
y=gets.to_i
l=gets.to_i
a=y<0? 2 : x==0? 0 : 1
x *= -1 if x < 0
y *= -1 if y < 0
a+=(x+l-1)/l
a+=(y+l-1)/l
p a
