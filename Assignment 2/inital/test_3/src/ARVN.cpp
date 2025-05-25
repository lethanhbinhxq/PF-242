#include "ARVN.h"

// TODO: Implement
ARVN::ARVN(Unit **unitArray, int size, string name) : Army(unitArray, size, name) {}

void ARVN::fight(Army* enemy, bool defense) {
    if (!defense) {
        enemy->fight(this, true);
        this->unitList->updateUnitScore(DECREASE_20_PERCENT_QUANTITY);
        this->unitList->removeWithQuantity(1);
    }
    else {
        enemy->fight(this, false);
        bool battleFlag = enemy->getBattleFlag();
        if (battleFlag) {
            this->unitList->updateUnitScore(DECREASE_20_PERCENT_WEIGHT);
        }
    }

    updateScores();
}

string ARVN::str() const {
    string arvnStr = "ARVN[";
    // arvnStr += "name=" + this->name;
    arvnStr += "LF=" + to_string(this->LF);
    arvnStr += ",EXP=" + to_string(this->EXP);
    arvnStr += ",unitList=";
    if (this->unitList) arvnStr += this->unitList->str();
    arvnStr += "]";
    return arvnStr;
}
