#include "Unit.h"

Unit::Unit(int quantity, int weight, Position pos)
{
    // TODO: implement
    this->quantity = quantity;
    this->weight = weight;
    this->pos.setRow(pos.getRow());
    this->pos.setCol(pos.getCol());
}

Unit::~Unit()
{
    // TODO: implement
}

Position Unit::getCurrentPosition() const
{
    return pos;
}