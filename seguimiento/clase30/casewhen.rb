def verificar a
  case a
  when 1
    puts "Es uno"
  when 2
    puts "Es dos"
  else
    puts "Es otro valor"
  end
end
def verificar2 a
  case a
  when "Uno"
    puts 1
  when "Dos"
    puts 2
  else
    puts a + "No aplica"
  end
end

def verificar3 a
  case a
  when 1
    puts "Uno"
  when "Dos"
    puts 2
  else
    0
  end
end
