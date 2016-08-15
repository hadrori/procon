v=0
gets.strip.chars do |c|
  v=if c=='L'
      v*2+1
    else
      v*2+2
    end
end
p v+1
