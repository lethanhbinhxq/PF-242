#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Infantry : public Unit {
private:
    InfantryType infantryType;
    bool checkPerfectSquare(int weight);
    int getPersonalNumber(int score, int year = 1975);
    string infantryTypeString() const;
public:
    Infantry(int quantity, int weight, const Position pos, InfantryType infantryType);
    ~Infantry();
    int getAttackScore();
    int getEnumType() const;
    string str() const;
    static InfantryType convertToInfantryType(string str);
};

#endif // INFANTRY_H