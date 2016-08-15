n=gets.to_i
a=[0]*[n,3].max
a[2] = 1
for i in (3...n) do
  a[i] = (a[i-1]+a[i-2]+a[i-3])%10007
end
p a[n-1]
