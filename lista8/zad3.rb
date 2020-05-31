
class Jawna
    def initialize(napis)
        @napis = napis
    end
    
    def to_s
        @napis
    end
    
    def zaszyfruj(klucz)
        wynik = ""
        @napis.each_char.to_a.each{ |c| wynik+=(klucz[c] || c)}
        return Zaszyfrowane.new(wynik)
    end
end

class Zaszyfrowane
    def initialize(napis)
        @napis = napis
    end
    
    def to_s
        @napis
    end
    
    def odszyfruj(klucz)
        klucz_rev = klucz.invert
        wynik = ""
        @napis.chars.each{ |c| wynik+=(klucz_rev[c] || c)}
        return Jawna.new(wynik)
    end
end

klucz = {'a' => 'b', 'b'=>'r', 'c'=>'z', 'd'=>'m', 'm'=>'c', 'z'=>'d', 'r'=>'y', 'y'=>'u', 'u'=>'a'}

text = Jawna.new('ruby')
puts "zaszyfrowane: #{zaszyfrowane=text.zaszyfruj(klucz)}"
puts "odszyfrowane: #{zaszyfrowane.odszyfruj(klucz)}"

