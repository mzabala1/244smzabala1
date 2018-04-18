#!/usr/bin/ruby

def echo()
  s=gets
  puts s
  return s.chomp
end

# Esto es un supuesto main de ruby

# echo


# Definir varible global
$count = 0

#Incrementa en 1 el contador

def genNroCons
  $count +=1
end
# plus

def suma (a,b)
  a+b
end

# define a class

class Estudiante
  attr_reader :name
  attr_accessor :age
  
  def initialize(name, age)
    @name = name.chomp
    @age = age
  end
  
  def print
    salida = "name: #{name} age: #{@age}"
    puts salida
  end
end

#Leerlas

print "Dijite el nombre del pendejo: "
name = gets
print "Estupido escriba sus anos: "
age = gets.to_i

est1 = Estudiante.new(name, age)
est1.print
