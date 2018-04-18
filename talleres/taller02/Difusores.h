#pragma once
/*
 * fichero : Difusores.h
 */

class Difusor{
 public:
  Difusor();
  Difusor(float anguloDifusion);
  ~Difusor();
  float obtAnguloDifusion();
  void estAnguloDifusion(float anguloDifusion);
  virtual bool potenciaDifusion(float potencia)=0;

 private:
  float anguloDifusion;
};

class DifusorCentral : public Difusor{
 public :
  DifusorCentral();
  DifusorCentral(float difusorCentral, float anguloDifusion);
  ~DifusorCentral();
  void establecerDifusorCentral(float difusorCentral);
  bool potenciaDifusion(float potencia);
 private:
  float difusorCentral;
};

class DifusorBivalente : public Difusor{
 public:
  DifusorBivalente();
  DifusorBivalente(float anguloPos, float anguloDifusion);
  ~DifusorBivalente();
  void estAnguloPos(float anguloPos);
  float obtAnguloPos();
  virtual bool potencialDifusio(float potencia)=0;
 private:
  float anguloPos;
};

class DifusorBivalenteCentral : public DifusorBivalente{
 public:
  DifusorBivalenteCentral();
  DifusorBivalenteCentral(float anguloDifusion,float anguloPos, float difusorBiC);
  ~DifusorBivalenteCentral();
  void establecerDifusorBiC(float difusorBiC);
  bool potenciaDifusion(float potencia);
 private:
  float difusorBiC;
};
