# Potrzebny gnuplot i ruby gem gnuplot
require "gnuplot"

class Funkcja
    def initialize
        @funkcja = Proc.new
    end
    
    def value(x)
        @funkcja.call(x)
    end
    
    def zerowe(a, b, e)
        roots = Array.new
        prev = a
        (a..b).step(0.001) do |x|
            if value(x)<e && value(x)>-e
               roots.push(x)
            elsif (value(prev) > 0 && value(x) < 0)
                roots.push("pomiedzy #{prev} i #{x}")
            elsif (value(prev) < 0 && value(x) > 0)
                roots.push("pomiedzy #{prev} i #{x}")
            end
            prev = x
        end
        return roots
    end
    
    def pole(a, b, delta=(b-a)/10000.0) # Riemann sum
        p=0.0
        (a...b).step(delta).to_a.each{|x| p += delta * value(x)}
        return p
    end
    
    def pochodna(x)
        h=0.00000000001
        return ((value(x+h)-value(x))/h).round(3)
    end

    def plot(a, b, filename)
        Gnuplot.open do |gp|
            Gnuplot::Plot.new(gp) do |plot|
                plot.terminal "jpeg"
                plot.output filename
                plot.title  "Wykres"
                plot.ylabel "y"
                plot.xlabel "x"
                
                x = (a..b).step((b-a).abs.to_f/1000.0).collect{|p| p.to_f}
                y = x.collect{|p| value(p)}
                
                plot.data << Gnuplot::DataSet.new([x, y]) do |ds|
                    ds.with = "lines"
                    ds.linewidth = 3
                end

            end
        end
    end
    
end

funkcja = Funkcja.new{ |x| x*x*x - 3*x*x + 2*x }
funkcja1 = Funkcja.new{ |x| 3*x*x - 5*x}
funkcja.zerowe(0,3,0.000001).each{ |a| print "miejsce zerowe f1: #{a}\n"}
puts
funkcja1.zerowe(0,5,0.00001).each{ |a| print "miejsce zerowe f2: #{a}\n"}
puts
funkcja3 = Funkcja.new{ |x| x*x}
puts "#{funkcja3.pole(-4,4)}"
(0..3).each {|a| puts "#{funkcja3.pochodna(a)}"}
funkcja.plot(-10, 10, "plik.jpeg")
