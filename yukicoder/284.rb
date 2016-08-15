n,=gets.split.map(&:to_i)
b=(1..n).to_a
gets.split.map(&:to_i).each { |x| b.insert(0,b.delete_at(x-1)) }
p b[0]
