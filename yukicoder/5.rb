l=gets.to_i
m=gets.to_i
n=gets.to_i
x=(l*100+m*25+n)%1000
a=x/100
x-=x/100*100
a+=x/25
x-=x/25*25
p x+a
