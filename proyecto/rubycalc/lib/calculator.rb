# coding: utf-8
require 'parser'
require 'ast'

class Calculator
  attr_accessor :memory
  attr_accessor :memory2
  attr_accessor :eol
  attr_accessor :eof
  attr_accessor :countAssigns
  attr_accessor :assigns
  attr_accessor :expressions
  attr_accessor :interactive
  attr_accessor :line

  def initialize()
    @memory = 0
    @memory2 = Hash.new(0)
    @eol = false
    @eof = false
    @assigns = Hash.new("")
    @countAssigns = 0
    @expressions = Array.new
    @interactive = false
    @line = ""
  end

  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
    
  end
  
  #Hago el push para añadirlo
  def add(expr)
    @expressions.push(expr)
    return expr
  end

  def insert(id,val)
    @assigns[countAssigns] = id.to_s + " <- " + val.to_s
    @countAssigns += 1
    @memory2[id] = val

  end

  def evalFile(file)
    while(true)
      linea1 = file.gets
      if(linea1)
        
        if (linea1!="\n")
          $calc.eval(linea1)
        else
          $calc.add("Needed an expresion")
        end
      else
        break
      end

    end

    @expressions.each{|expr| puts expr}

    @expressions.clear
  end

  def search(id)
    if(@memory2.keys.include?(id))
      return @memory2[id]
    else
      return 0      
    end
  end
end
