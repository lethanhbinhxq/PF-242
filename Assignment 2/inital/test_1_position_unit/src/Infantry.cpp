#include "Infantry.h"
bool Infantry::checkPerfectSquare(int weight) {
    int sqrtNumber = sqrt(weight);
    return (sqrtNumber * sqrtNumber == weight);
}

int Infantry::getPersonalNumber(int score, int year) {
    int sumDigit = 0;
    while (year > 0) {
        sumDigit += year % 10;
        year /= 10;
    }

    sumDigit += score;
    while (sumDigit >= 10) {
        int temp = 0;
        while (sumDigit > 0) {
            temp += sumDigit % 10;
            sumDigit /= 10;
        }
        sumDigit = temp;
    }

    return sumDigit;
}

string Infantry::infantryTypeString() const {
    switch(this->infantryType) {
        case SNIPER: return "SNIPER";
        case ANTIAIRCRAFTSQUAD: return "ANTIAIRCRAFTSQUAD";
        case MORTARSQUAD: return "MORTARSQUAD";
        case ENGINEER: return "ENGINEER";
        case SPECIALFORCES: return "SPECIALFORCES";
        case REGULARINFANTRY: return "REGULARINFANTRY";
    }
    return "";
}

InfantryType Infantry::convertToInfantryType(string str) {
    if (str == "SNIPER") return SNIPER;
    if (str == "ANTIAIRCRAFTSQUAD") return ANTIAIRCRAFTSQUAD;
    if (str == "MORTARSQUAD") return MORTARSQUAD;
    if (str == "ENGINEER") return ENGINEER;
    if (str == "SPECIALFORCES") return SPECIALFORCES;
    if (str == "REGULARINFANTRY") return REGULARINFANTRY;
    return SNIPER;
}

Infantry::Infantry(int quantity, int weight, const Position pos, InfantryType infantryType) : Unit(quantity, weight, pos) {
    this->infantryType = infantryType; 
}

Infantry::~Infantry() {}

int Infantry::getAttackScore() {
    int score = (int)(this->infantryType) * 56 + this->quantity * this->weight;
    
    if (this->infantryType == SPECIALFORCES && checkPerfectSquare(this->weight)) {
        score += 75;
    }

    int personalNumber = getPersonalNumber(score);
    if (personalNumber > 7) {
        double newQuantity = this->quantity + this->quantity * 0.2;
        this->quantity = ceil(newQuantity);
        // score = (int)(this->infantryType) * 56 + this->quantity * this->weight;
    }
    else if (personalNumber < 3) {
        double newQuantity = this->quantity - this->quantity * 0.1;
        this->quantity = ceil(newQuantity);
        // score = (int)(this->infantryType) * 56 + this->quantity * this->weight;
    }
    score = (int)(this->infantryType) * 56 + this->quantity * this->weight;
    return score;
}

int Infantry::getEnumType() const {
    return this->infantryType;
}

string Infantry::str() const {
    string infantryStr = "Infantry[";
    infantryStr += "infantryType=" + infantryTypeString();
    infantryStr += ",quantity=" + to_string(this->quantity);
    infantryStr += ",weight=" + to_string(this->weight);
    infantryStr += ",position=" + this->pos.str();
    infantryStr += "]";
    return infantryStr;
}

// TODO: implement