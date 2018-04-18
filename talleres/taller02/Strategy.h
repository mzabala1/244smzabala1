#pragma once

class Strategy{
 public:
  Strategy();
  ~Strategy();
  void operation();
};

class ConcreteStrategyA :public Strategy{
 public:
  ConcreteStrategyA();
  ~ConcreteStrategyA();
  void operation();
};

class ConcreteStrategyB : public Strategy{
 public:
  ConcreteStrategyB();
  ~ConcreteStrategyB();
  void operation();
};

class StrategyClient{
 public:
  StrategyClient();
  ~StrategyClient();
  void setStrategy(Strategy s);
  void performOperation();
 private:
  Strategy strategy;
};

