puts gets.split.map(&:to_i).inject{|x,y|x%y==0} ? "YES" : "NO"
