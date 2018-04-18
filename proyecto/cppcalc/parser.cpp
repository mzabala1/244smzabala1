#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

using namespace std;

Parser::Parser(istream* in) {
  scan = new Scanner(in);
}

Parser::~Parser() {
  try {
    delete scan;
  } catch (...) {}
}

AST* Parser::parse() {
  return Prog();
}

AST* Parser::Prog() {
  AST* result = Expr();
  Token* t = scan->getToken();

  if (t->getType() != eof) {
    cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
    throw ParseError;
  }

  return result;
}

AST* Parser::Expr() {
  return RestExpr(Term());
}

// +, -
AST* Parser::RestExpr(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == add) {
    return RestExpr(new AddNode(e,Term()));
  }

  if (t->getType() == sub)
    return RestExpr(new SubNode(e,Term()));
   
  scan->putBackToken();

  return e;
}

AST* Parser::Term() {
  return RestTerm(Storable());
}

// *, /, %

AST* Parser::RestTerm(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == times){
    return RestTerm(new TimesNode(e,Storable()));
  }
  if (t->getType() == divide){
    return RestTerm(new DivideNode(e,Storable()));
  }
  if (t->getType() == modulo){
    return RestTerm(new ModuloNode(e,Storable()));
  }

  scan->putBackToken();

  return e;
}


// write your Term() code here. This code is just temporary
// so you can try the calculator out before finishing it.
// Token* t = scan->getToken();

//    if (t->getType() == number) {
//       istringstream in(t->getLex());
//       int val;
//       in >> val;
//       return new NumNode(val);
//    }

//    cout << "Term not implemented" << endl;

//    throw ParseError; 
// } }
//    cout << "RestTerm not implemented" << endl;
//    throw ParseError; 
// }

//retorna el MemOperation Segun la gramatica

AST* Parser::Storable() {

  AST* result = MemOperation(Factor());
  return result;
}

//Sigo con la gramatica, S, P, y M

AST* Parser::MemOperation(AST* result){

  Token* t = scan->getToken();

  if(t->getType() == keyword){
    if(t->getLex() == "S")
      return new StoreNode(result);

    else if(t->getLex() == "P")
      return new PlusNode(result);

    else if(t->getLex() == "M")
      return new MinusNode(result);
  }
  scan->putBackToken();

  return result;
}

AST* Parser::Factor() {
  Token* t = scan->getToken();
     
  if (t->getType() == number) {
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }

  if(t->getType()==identifier){
    scan->putBackToken();
    return Assignable();
  }

  if (t->getType() == keyword){
    if(t->getLex() == "R"){
      return new RecallNode();
    }else if(t->getLex() == "C"){
      return new ClearNode();
    }else{
     
      cout<<"Syntax error:  "
	  << t->getLex()<<"at line: "<< t->getLine()
	  << " col: " << t->getCol() << endl;
      throw ParseError;
    }
  }
   

  if(t->getType() == lparen){
     
    AST* result = Expr();
    t = scan->getToken();

    if(t->getType() == rparen){
      return result;
    }else{ 
      cout<<"Syntax error: expected ')', found "
	  << t->getType() <<"at line: "<< t->getLine()
	  << " col: " << t->getCol() << endl;
      throw ParseError;
    }
  }
  cout << "Expected number, R or '('" << endl;
  throw ParseError;
}

//identifier Assign

AST* Parser::Assignable(){
  Token* t = scan->getToken();
  if((t->getType())==identifier){
    string lex = t->getLex();
    AST* result = Assign(lex);
    return result;
  }else{
    cout << "identifier expected" << endl;
  }
}


// Si encuentra un token '=' (assignacion) crea el AssignNode, si no, retrocede el token--Expr Assign

AST* Parser::Assign(string s){

  Token* t= scan->getToken();
  if(t->getType() == assign){
    return new AssignNode(s,Expr());
  }else{
    scan->putBackToken();
    return new IdentifierNode(s);
  }
}
