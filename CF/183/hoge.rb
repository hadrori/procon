fib1 = fib2 = 1
dp = Array.new(1000010,0)
dp[0] = 1
while fib1 <= 1000000
  fib1 += fib2
  fib2 = fib1-fib2
  puts(fib1)
  for j in 0..(1000000-fib1); dp[j+fib1] = dp[j+fib1]+dp[j]; end
end
puts(dp[1000000])
