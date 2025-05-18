#include "Unit.h"

//!----------------------------------------------
//! Lớp Unit
//!----------------------------------------------
Unit::Unit(): quantity(0), weight(0), pos(Position()), terrainModifier(1) {}

Unit::Unit(int quantity, int weight, Position pos) {
    this->quantity = quantity;
    this->weight = weight;
    this->pos.setRow(pos.getRow());
    this->pos.setCol(pos.getCol());
    this->terrainModifier = 1;
}

Unit::~Unit() {}

Position Unit::getCurrentPosition() const {
    return this->pos;
}

int Unit::getQuantity() const {
    return this->quantity;
}

void Unit::setQuantity(int quantity) {
    this->quantity = quantity;
}

int Unit::getWeight() const {
    return this->weight;
}

void Unit::setWeight(int weight) {
    this->weight = weight;
}

void Unit::setTerrainModifier(double terrainModifier) {
    this->terrainModifier = terrainModifier;
}

int Unit::getAttackScoreImmutable() {
    return this->attackScoreImmutable;
}

void Unit::setAttackScoreImmutable(int score) {
    this->attackScoreImmutable = score;
}