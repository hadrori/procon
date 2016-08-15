a = gets.split
b = gets.split

ans = if a[1].to_i == b[1].to_i
        "-1"
      elsif a[1].to_i > b[1].to_i
        a[0]
      else
        b[0]
      end
puts ans
