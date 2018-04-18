#include <sstream>
#include <string>
#include "ast.h"
#include <iostream>
#include "calculator.h"

using namespace std;

// for debug information uncomment
// #define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif
   
   try {
      delete subTree;
   } catch (...) {}

}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int TimesNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivideNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

//Modulo

ModuloNode::ModuloNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int ModuloNode::evaluate() {
   return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

StoreNode::StoreNode(AST* sub):
  UnaryNode(sub)
{}

int StoreNode::evaluate(){
  calc->store(getSubTree()->evaluate());
  return calc->recall();
}

NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}

//Creacion y evaluacion del nodo Minus

MinusNode::MinusNode(AST* sub):
  UnaryNode(sub)
{}

int MinusNode::evaluate(){
  calc->minus(getSubTree()->evaluate());
  return calc->recall();
}

//Creacion y evaluacion del nodo Plus

PlusNode::PlusNode(AST* sub):
  UnaryNode(sub)
{}

int PlusNode::evaluate(){
  calc->plus(getSubTree()->evaluate());
  return calc->recall();
}

//El AssignNode covierte el flujo de int a str para que se pueda concatenar

AssignNode::AssignNode(string id, AST* sub):
  UnaryNode(sub),
  id(id)
{}

int AssignNode::evaluate(){
  int val = getSubTree()->evaluate();
  string assignation;

//flujo
  stringstream convert;

  convert<<val;
  assignation = convert.str();

  calc->insert(id,val);
  calc->pushAssign(id + " <- " + assignation);

  return val;
}


IdentifierNode::IdentifierNode(string id):
  AST(),
  id(id)
{}

int IdentifierNode::evaluate(){
  return calc->obtMemory2(id);
}

RecallNode::RecallNode():
  AST()
{}

int RecallNode::evaluate(){
  return calc->recall();
}

ClearNode::ClearNode():
  AST()
{}

int ClearNode::evaluate(){
  calc -> clear();
  int a=0;
  return a;
}
