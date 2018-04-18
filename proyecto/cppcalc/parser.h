#pragma once

#include <string>
#include "ast.h"
#include "scanner.h"

class Parser {
 public:
   Parser(istream* in);
   ~Parser();

   AST* parse();

 private:
   AST* Prog();
   AST* Expr();
   AST* RestExpr(AST* e);
   AST* Term();
   AST* RestTerm(AST* t);
   AST* Storable();
   AST* MemOperation(AST* e);
   AST* Factor();
   AST* Assignable();
   AST* Assign(string id);
   
   Scanner* scan;
};


