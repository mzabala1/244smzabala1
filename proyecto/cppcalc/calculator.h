#pragma once

#include <map>
#include <vector>
#include <string>
 
using namespace std;


class Calculator {
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   int recall();
   void minus(int val);
   void plus (int val);
   void Interactive();
   void insert(string id,int val);
   bool isEOL();
   void clear();
   void clearAssigns();
   vector<string> getAssigns();
   void pushAssign(string assign);
   bool isDef(string nomVar);
   int obtMemory2(string id);

 private:
   bool eol;
   int memory;
   bool interactive;
   map<string,int> memory2;
   vector<string> assigns;
};

extern Calculator* calc;

