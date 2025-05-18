#include "Army.h"

void Army::normalizeArmyData() {
    const int MIN_VALUE = 0;
    const int MAX_LF = 1000;
    const int MAX_EXP = 500;

    this->LF = max(this->LF, MIN_VALUE);
    this->LF = min(this->LF, MAX_LF);

    this->EXP = max(this->EXP, MIN_VALUE);
    this->EXP = min(this->EXP, MAX_EXP);
}

bool Army::checkSpecialNumber(int S, int base) {
    while (S > 0) {
        if (S % base > 1) {
            return false;
        }
        S /= base;
    }
    return true;
}

Army::Army(): LF(0), EXP(0), name(""), unitList(nullptr){}

Army::Army(Unit **unitArray, int size, string name) {
    this->name = name;
    this->LF = 0;
    this->EXP = 0;
    this->battleFlag = false;
    int bases[] = {3, 5, 7};
    bool specialFlag = false;

    const int SPECIAL_CAPACITY = 12;
    const int NORMAL_CAPACITY = 8; 

    for (int i = 0; i < size; i++) {
        if (dynamic_cast<Vehicle*>(unitArray[i])) {
            this->LF += unitArray[i]->getAttackScore();
        }
        else {
            this->EXP += unitArray[i]->getAttackScore();
        }
    }

    normalizeArmyData();

    int S = this->LF + this->EXP;
    for (int i = 0; i < sizeof(bases) / sizeof(int); i++) {
        if (checkSpecialNumber(S, bases[i])) {
            specialFlag = true;
            break;
        }
    }

    if (specialFlag) {
        this->unitList = new UnitList(SPECIAL_CAPACITY);
    }
    else {
        this->unitList = new UnitList(NORMAL_CAPACITY);
    }

    for (int i = 0; i < size; i++) {
        this->unitList->insert(unitArray[i]);
    }
}

int Army::getLF() {
    return this->LF;
}

int Army::getEXP() {
    return this->EXP;
}

bool Army::getBattleFlag() {
    return this->battleFlag;
}

UnitList* Army::getUnitList() const {
    return this->unitList;
}

void Army::setLF(int LF) {
    this->LF = LF;
}

void Army::setEXP(int EXP) {
    this->EXP = EXP;
}

void Army::updateScores() {
    vector<Unit*> infantryList = this->unitList->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleList = this->unitList->getUnitsByType(VEHICLE_UNIT);
    int newEXP = 0;
    int newLF = 0;

    // for (int i = 0; i < vehicleList.size(); i++) {
    //     cout << vehicleList[i]->getAttackScore() << endl;
    // }

    for (int i = 0; i < infantryList.size(); i++)  {
        newEXP += infantryList[i]->getAttackScore();
    }
    for (int i = 0; i < vehicleList.size(); i++) {
        newLF += vehicleList[i]->getAttackScore();
    }
    this->EXP = newEXP;
    this->LF = newLF;
    normalizeArmyData();
}

void Army::removeUnit(vector<Unit*> infantryList, vector<Unit*> vehicleList) {
    for (int i = 0; i < infantryList.size(); i++) {
        this->unitList->remove(infantryList[i]);
    }
    for (int i = 0; i < vehicleList.size(); i++) {
        this->unitList->remove(vehicleList[i]);
    }
}

void Army::confiscate(Army* winner, Army* loser) {
    UnitList* winnerUL = winner->getUnitList();
    UnitList* loserUL = loser->getUnitList();
    while(!(winnerUL->isFull()) && !(loserUL->isEmpty())) {
        winnerUL->insert(loserUL->pop_back_unit());
    }
    winner->updateScores();
    loser->updateScores();
}
