class Token
  attr_reader :type, :line, :col

  def initialize(type,lineNum,colNum)
    @type = type
    @line = lineNum
    @col = colNum
  end
end

#Herencia en ruby por medio del hijo < padre

class LexicalToken < Token
  attr_reader :lex
  
  def initialize(type,lex,lineNum,colNum)
    super(type,lineNum,colNum)
    
    @lex = lex
  end
end
