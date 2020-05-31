
class Fixnum

    def czynniki
        (1..self/2).select{ |n| self % n == 0} + [self]
    end
    
    def suma
        sum=0
        self.czynniki.each{ |x| sum+=x }
        return sum
    end
    
    def doskonala
        return true if self.suma-self == self
        return false
    end
    
    def ack(y)
        return y+1 if self==0
        return (self-1).ack(1) if y==0
        return (self-1).ack(self.ack(y-1))
    end
    
    def slownie
        hash_tab = {0 => "zero", 1=>"jeden", 2=>"dwa", 3=>"trzy", 4=>"cztery", 5=>"piec", 6=>"szesc", 7=>"siedem", 8=>"osiem", 9=>"dziewiec"}
        num = self
        str = ""
        while num>0
            str += hash_tab[num%10]+" "
            num = num/10
        end
        return str.split.reverse.join(" ")
    end
end


[7,8,14,17,32,78].each{ |a| print "czynniki #{a} = #{a.czynniki}\n"}

puts "doskonale: #{(1..1000).select{ |n| n.doskonala == true}}"

puts "ack(2, 1) = #{2.ack(1)}" 
puts "ack(3, 1) = #{3.ack(1)}"
puts "ack(3, 2) = #{3.ack(2)}"

(1..12).each{|a| puts a.slownie}
puts 123.slownie
