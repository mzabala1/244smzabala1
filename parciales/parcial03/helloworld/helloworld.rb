#!/usr/bin/ruby

# implemente la funcion isHelloWorld que
# identifique si las palabras Hello World
# en cualquier formato de mayusculas y minusculas
# contiene Hello World

def isHelloWorld(a)
  
  hi= "Hello world"
  hi.chomp!

  if(a.capitalize.chomp==hi)
    return true
  else
    return false
  end
end
