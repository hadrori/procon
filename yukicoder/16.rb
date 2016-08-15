n = gets.to_i
for i in 1..n
  f = i%3 == 0
  g = i%5 == 0
  h = f & g
  if h
    puts "FizzBuzz"
  elsif f
    puts "Fizz"
  elsif g
    puts "Buzz"
  else
    p i
  end
end
