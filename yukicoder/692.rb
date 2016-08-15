n = gets.to_i
a = (1..n).to_a
n.times do |i|
  b = [i+1]
  gets.split.each.with_index do |s, i|
    b << i+1 if s == "nyanpass"
  end
  a &= b
end
p a.length == 1 ? a[0] : -1
