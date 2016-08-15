n=gets.to_i
a=gets.split.map(&:to_i).sort
n.times do |i|
  if a[i] != a[0]
    puts (n-i).to_s+' '+i.to_s
    break
  end
  if i == n-1
    if a[0] == (n-1)*2
      puts n.to_s+' 0'
    else
      puts '0 '+n.to_s
    end
  end
end
