require 'ast'
require 'scanner'
require 'token'
require 'calcex'

# cuando comienza por minuscula lo toma como metodo, si comienza por mayus lo toma como una clase

class Parser
  def initialize(istream)
    @scan = Scanner.new(istream)
    @bool = false
  end

  def parse
    return Prog()
  end
  
  private

  def Prog
    ListExpr(nil)
  end

  def ListExpr(e)
    expr = Expr()
    hijo = ListExprNode.new(e,expr)

    t = @scan.getToken
    
    if t.type == :eol
      a = ListExpr(hijo)
      return a
    end

    if (t.type == :eof)
      if(e != nil)
        return e
      else
        return hijo
      end
    end
  end
  
  def Expr
    return RestExpr(Term())
  end
  
  def RestExpr(e) 
    t = @scan.getToken
    
    if t.type == :add then
      return RestExpr(AddNode.new(e,Term()))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term()))
    end

    @scan.putBackToken

    return e
  end
  
  def Term
    return RestTerm(Storable())

    puts "Term Not Implemented Yet\n"
    raise ParseError.new
  end

  def RestTerm(e)
    t = @scan.getToken
    
    if t.type == :times then
      return RestExpr(TimesNode.new(e,Storable()))
    end
    
    if t.type == :divide then
      return RestExpr(DivideNode.new(e,Storable()))
    end

    if t.type == :modulo then
      return RestTerm(ModuloNode.new(e,Storable()))
    end
    
    @scan.putBackToken
    
    return e

    #raise es como el throw
    puts "RestTerm Not Implemented Yet"
    raise ParseError.new

  end
  
  def Storable()
    return MemOperation(Factor())
  end

  def MemOperation(e)
    t = @scan.getToken()
    if (t.type==:keyword)
      if (t.lex=="S")
        return StoreNode.new(e)
      elsif(t.lex=="M")
        return MinusNode.new(e)
      elsif(t.lex=="P")
        return PlusNode.new(e)
      end
    end

    @scan.putBackToken
    return e
    
  end

  def Assignable
    t = @scan.getToken
    if(t.type == :identifier)

      result = Assign(t.lex.to_s)
      return result
    end
  end

  def Assign(id)
    t = @scan.getToken
    if(t.type == :assign)
      return AssignNode.new(id,Expr())
    end
    @scan.putBackToken
    return IdentifierNode.new(id)
  end

  def Factor()

    t = @scan.getToken

    if t.type == :number then
      return NumNode.new t.lex.to_i
      
    elsif t.type == :keyword
      if t.lex == "R"
        return RecallNode.new
      elsif t.lex == "C"
        return ClearNode.new
      end
    elsif t.type == :lparen
      result = Expr()
      t = @scan.getToken
      if t.type == :rparen
        return result
      else
        puts "Parser Error: expected ) found: #{t.lex}"
        puts "at line: #{t.line} col: #{t.col}"
      end
    end

    @scan.putBackToken
    return Assignable()
  end
end
