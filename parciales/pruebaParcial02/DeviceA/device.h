#pragma once

class Device {
 public:
  Device();
  Device(int factorOne);
  virtual ~Device() = 0;
  virtual int compute() const = 0;
  int getFactorOne() const;
 private:
  int factorOne;
};

class DevByFive : public Device {
 public:
  DevByFive(int factorOne);
  ~DevByFive();
  int compute() const;
};

class DevByTen : public Device {
 public:
  DevByTen(int factorOne);
  ~DevByTen();
  int compute() const;
};

class Device2 : public Device {
 public:
  Device2();
  Device2(int factorOne, int factorTwo);
  ~Device2();
  int getFactorTwo() const;
 private:
  int factorTwo;
};

class Dev2MinusFive : public Device2 {
 public:
  Dev2MinusFive(int factorOne, int factorTwo);
  ~Dev2MinusFive();
  int compute() const;
};

class Dev2AddTen : public Device2 {
 public:
  Dev2AddTen(int factorOne, int factorTwo);
  ~Dev2AddTen();
  int compute() const;
};
