#ifndef _H_ARMY_H_
#define _H_ARMY_H_

#include "UnitList.h"
using namespace std;

class Army
{
protected:
    int LF, EXP;
    string name;
    UnitList *unitList;
    bool battleFlag;

    void normalizeArmyData();
    bool checkSpecialNumber(int S, int base);

public:
    Army();
    Army(Unit **unitArray, int size, string name);
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
    int getLF();
    int getEXP();
    UnitList* getUnitList() const;
    void setLF(int LF);
    void setEXP(int EXP);
    void updateScores();
    void removeUnit(vector<Unit*> infantryList = {}, vector<Unit*> vehicleList = {});
    void confiscate(Army* winner, Army* loser);
    bool getBattleFlag();
};

#endif
