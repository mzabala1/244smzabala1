#include <iostream>
#include "Strategy.h"

using namespace std;

StrategyClient::StrategyClient(){}

StrategyClient::~StrategyClient(){}

void StrategyClient::setStrategy(Strategy s){
  strategy = s;
}

void StrategyClient::performOperation(){
  strategy.operation();
}

Strategy::Strategy(){}

Strategy::~Strategy(){}

ConcreteStrategyA::ConcreteStrategyA(){}

ConcreteStrategyA::~ConcreteStrategyA(){}

void ConcreteStrategyA::operation(){
  cout<< "Hello strategy A"<<endl;
}


ConcreteStrategyB::ConcreteStrategyB(){}

ConcreteStrategyB::~ConcreteStrategyB(){}

void ConcreteStrategyB::operation(){
  cout<< "Hello strategy B"<<endl;
}
