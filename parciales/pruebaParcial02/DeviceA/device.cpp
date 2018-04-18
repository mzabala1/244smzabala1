#include "device.h"

Device::Device() :
  factorOne(10)
{}

Device::Device(int factorOne) :
  factorOne(factorOne)
{}

Device::~Device() {
}

int Device::getFactorOne() const {
  
  return factorOne;
}

DevByFive::DevByFive(int factorOne) :
  Device(factorOne)
{}

DevByFive::~DevByFive() {}

int DevByFive::compute() const {
  return getFactorOne() * 5;
}

DevByTen::DevByTen(int factorOne) :
  Device(factorOne)
{}

DevByTen::~DevByTen() { }

int DevByTen::compute() const {
  return getFactorOne() * 10;
}

Device2::Device2() :
  Device(),
  factorTwo(20)
{}

Device2::Device2(int factorOne, int factorTwo) :
  Device(factorOne),
  factorTwo(factorTwo)
{}

Device2::~Device2() { }

int Device2::getFactorTwo() const {
  return factorTwo;
}


Dev2MinusFive::Dev2MinusFive(int factorOne, int factorTwo) :
  Device2(factorOne,factorTwo)
{}

Dev2MinusFive::~Dev2MinusFive() { }

int Dev2MinusFive::compute() const {
  
  return getFactorOne() + getFactorTwo() - 5;
}

Dev2AddTen::Dev2AddTen(int factorOne, int factorTwo) :
  Device2(factorOne, factorTwo)
{}

Dev2AddTen::~Dev2AddTen() {}

int Dev2AddTen::compute() const {
  
  return getFactorOne() + getFactorTwo() + 10;
}


