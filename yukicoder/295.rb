a,b,c,d,e,f=(gets+' '+gets+' '+gets).split.map(&:to_i)
g=[a,e-[b,e].min].min
a-=g-[c+g,f].min
p a
