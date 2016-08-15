p 3.times.map{gets.split.map(&:to_i).inject(:*)/10}.inject(:+)
