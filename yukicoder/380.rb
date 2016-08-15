h,w,n,k=gets.split.map(&:to_i)
puts h*w%n == k%n ? "YES" : "NO"
