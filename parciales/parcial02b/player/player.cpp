#include "player.h"
#include <iostream>

using namespace std;

Player::Player(unsigned short nLifes,
               unsigned short nBullets,
               unsigned short armorLevel,
               unsigned short shotFactor) :
  nLifes(nLifes),
  nBullets(nBullets),
  armorLevel(armorLevel),
  shotFactor(shotFactor)
{}

void Player::setLifes(unsigned short nLifes){
  if(isAlive()){
    this-> nLifes = nLifes + nLifes;
  }
}

void Player::setArmorLevel(unsigned short level){
  if(isAlive()){
    this-> armorLevel = armorLevel + level;
  }
}

void Player::chargeCartridge(unsigned short nBullets){
  if(isAlive()){
    this->nBullets = nBullets + nBullets;
  }
}
  
void Player::receiveShot(){
  if(nLifes > 0 && armorLevel == 0){
    nLifes--;
    return;
  }
  if(armorLevel >= shotFactor){
    armorLevel = armorLevel - shotFactor;
  }
  else{
    armorLevel = 0;
  }
  if(nLifes > 0 && armorLevel == 0){
    nLifes--;
    return;
  }
}
void Player::fireMachineGun(){
  if(isAlive()){
    if(nBullets >= 0){
      nBullets--;
    }
  }
  return;
}

bool Player::isAlive()const{
  if(getLifes() == 0){
    return false;
  }
  else{
    return true;
  }
}

unsigned short Player::getLifes()const{
  return nLifes;
}

unsigned short Player::getArmorLevel()const{
  return armorLevel;
}

unsigned short Player::getNbrBullets()const{
  return nBullets;
}

