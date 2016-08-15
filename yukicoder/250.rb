class Solver
  def initialize
    @fac = [0]*3001
    @fac[0] = 1
    for i in 1..3000
      @fac[i]=i*@fac[i-1]
    end
  end

  def comb(n,k)
    @fac[n]/@fac[k]/@fac[n-k]
  end

  def run
    gets.to_i.times do
      d,x,t=gets.split.map(&:to_i)
      puts comb(x+d-1,d-1) <= t ? "AC" : "ZETUBOU"
    end
  end
end

Solver.new.run
