#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


Calculator::Calculator():
  memory(0),
  interactive(false)
{}

int Calculator::eval(string expr) {

   Parser* parser = new Parser(new istringstream(expr));
   
   AST* tree = parser->parse();
   
   int result = tree->evaluate();
   
   delete tree;
   
   delete parser;
   
   return result;
}

void Calculator::store(int val) {
   memory = val;
}

int Calculator::recall() {
   return memory;
}

void Calculator::minus(int val){
  memory = memory - val;
}

vector<string> Calculator::getAssigns(){
  return assigns;
}
void Calculator::pushAssign(string assign){
  assigns.push_back(assign);
}

void Calculator::plus(int val){
  memory = memory + val;
}

bool Calculator::isEOL(){
  return eol;
}

void Calculator::Interactive(){
  interactive = true;
}

void Calculator::clear(){
  memory = 0;
  memory2.clear();
}

void Calculator::clearAssigns(){
  assigns.clear();
}

void Calculator::insert(string id,int val){
  if(!memory2.empty())
    for (map < string, int>::iterator

	   it=memory2.begin();
	 it!=memory2.end(); ++it){

      if(it->first==id){
	memory2.at(id) = val;
      }else{
	memory2.insert(pair<string, int >(id,val));
      }
    }
  memory2.insert(pair<string, int>(id,val));
}

bool Calculator::isDef(string nomVar){
  for (map<string,int>::iterator
	 it=memory2.begin();
       it!=memory2.end(); ++it){
    if(it->first==nomVar){
      return true;
    }
  }
  return false;
}

int Calculator::obtMemory2(string id){
  for (map<string,int>::iterator
	 it=memory2.begin();
       it!=memory2.end(); ++it){
    if(it->first==id){
      return it->second;
    }
  }
  return 0;
}
