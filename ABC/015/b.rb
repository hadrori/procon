gets
a=gets.split.map(&:to_i).select{|v|v>0}
p (a.inject(:+)*1.0/a.size).ceil.to_i
