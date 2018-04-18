require 'set'

#El @ es una variable instancia, un atributo de la clase
#Elreturn ni los () son necesarios en ruby

class BinaryNode
  attr_reader :left, :right
  
  def initialize(left,right)
    @left = left
    @right = right
  end
end

class UnaryNode
  attr_reader :subTree
  
  def initialize(subTree)
    @subTree = subTree
  end
end

class ListExprNode < BinaryNode
  def initialize(left,right)
    @left = left
    @right = right
  end

  def evaluate
    if(@left != nil)
      @left.evaluate
    end
    $calc.add(@right.evaluate)
  end

end

class AssignNode < UnaryNode
  def initialize(id,subTree)
    super(subTree)
    @id=id
  end

  def evaluate
    val = @subTree.evaluate
    $calc.insert(@id,val)

    #Asigna
    return val.to_i
  end
end

class IdentifierNode
  def initialize(id)
    @id=id
  end

  def evaluate
    return $calc.search(@id).to_i
  end
end

#to_i convierte el token a integer

class AddNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
  
  def evaluate()
    return @left.evaluate.to_i + @right.evaluate.to_i
  end
end

class SubNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
  
  def evaluate() 
    return @left.evaluate.to_i - @right.evaluate.to_i
  end
end

class NumNode
  def initialize(num)
    @num = num
  end

  def evaluate()
    @num
  end
end

class StoreNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end

  def evaluate()
    $calc.memory = subTree.evaluate.to_i
  end
end

class PlusNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end

  def evaluate
    $calc.memory+=subTree.evaluate.to_i
  end
end

class MinusNode < UnaryNode
  def initialize(subTree)
    super(subTree)
  end

  def evaluate
    $calc.memory-=subTree.evaluate.to_i
  end
end

class ClearNode
  def evaluate
    $calc.memory2.clear
    $calc.memory=0
  end
end

class RecallNode
  def evaluate
    $calc.memory.to_i
  end
end

class TimesNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
  
  def evaluate 
    return @left.evaluate.to_i * @right.evaluate.to_i
  end
end

class DivideNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
  
  def evaluate()
    return @left.evaluate.to_i / @right.evaluate.to_i
  end
end

class ModuloNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
  
  def evaluate 
    return @left.evaluate.to_i % @right.evaluate.to_i
  end
end
