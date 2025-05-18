#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    double terrainModifier;
    int attackScoreImmutable;
public:
    Unit();
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    int getAttackScoreImmutable();
    void setAttackScoreImmutable(int score);
    Position getCurrentPosition() const;
    virtual string str() const = 0;
    int getQuantity() const;
    void setQuantity(int quantity);
    int getWeight() const;
    void setWeight(int weight);
    void setTerrainModifier(double terrainModifier);
    virtual int getEnumType() const = 0;
};

#endif // UNIT_H
