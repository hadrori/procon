a=(0..9).to_a
gets.to_i.times do
  b=gets.split
  c=b[0,4].map(&:to_i)
  a = b[4]=="YES"? a&c : a-c
end
p a[0]
