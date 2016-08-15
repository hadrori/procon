n=2025-gets.to_i
for i in (1..9)
  puts "#{i} x #{n/i}" if n%i==0 and n/i < 10
end
