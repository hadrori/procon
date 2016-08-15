lb=1
ub=1000000001
while ub-lb>1
  m=(lb+ub)/2
  puts '? '+m.to_s
  STDOUT.flush
  if gets.to_i==1
    lb=m
  else
    ub=m
  end
end
puts '! '+lb.to_s
