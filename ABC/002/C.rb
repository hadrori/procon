a = gets.split.map(&:to_f)
p ((a[2]-a[0])*(a[5]-a[1])-(a[3]-a[1])*(a[4]-a[0])).abs/2
