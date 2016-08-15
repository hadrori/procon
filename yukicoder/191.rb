p (gets.to_i-2*gets.split.map(&:to_i).inject(0){|a,b|a+(b%2)}).abs
